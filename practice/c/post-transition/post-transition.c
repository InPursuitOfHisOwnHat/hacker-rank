#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_STRING_LENGTH 6

struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int office_id = 0; office_id < t.offices_count; office_id++) {
        printf("\t%d:\n", office_id);
        for (int package = 0; package < t.offices[office_id].packages_count; package++) {
            printf("\t\t%s\n", t.offices[office_id].packages[package].id);
        }
    }
}

// =======================================================================================================================================

ssize_t add_package_to_queue(package** ps, const ssize_t size, const package p) {


    if (size == 0) {
        // cakelog("First item in the list");
        *ps = malloc(sizeof(p));
        (*ps)[0] = p;
        return 1;
    }
    else {
        // cakelog("List already greater than 0 Adding package [%s] to queue", p.id);
        ssize_t new_size = size+1;
        *ps = realloc(*ps, new_size*sizeof(p));
        (*ps)[size] = p;
        // cakelog("Done", p.id);
        return new_size;

    }

}

void add_package_to_queue_test() {

    int count = 0;
    package* ps;

    package p;
    p.id = "A";
    p.weight = 45;

    count = add_package_to_queue(&ps, count, p);
    // cakelog("Added first package to queue with id [A], queue length now [%d]", count);

    package q;
    q.id = "B";
    q.weight = 100;

    count = add_package_to_queue(&ps, count,q);
    // cakelog("Added second package to queue with id [B], queue length now [%d]", count);

    package r;
    r.id = "C";
    r.weight = 134;
    count = add_package_to_queue(&ps, count, r);
    // cakelog("Added third package to queue with id [C], queue length now [%d]", count);

    package s;
    s.id = "D";
    s.weight = 124;
    count = add_package_to_queue(&ps, count, s);
    // cakelog("Added fourth package to queue with id [C], queue length now [%d]", count);

    package t;
    t.id = "E";
    t.weight = 34;
    count = add_package_to_queue(&ps, count, t);
    // cakelog("Added fifth package to queue with id [C], queue length now [%d]", count);

    for (int i=0; i<count; i++) {
        printf("[%d]: Package ID: [%s], Weight: [%d]\n", i, ps[i].id, ps[i].weight);
    }
}

// =======================================================================================================================================

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {

    // cakelog("Attempting to send all packages from office [%d], town [%s] to office [%d], town[%s]", source_office_index, source->name, target_office_index, target->name);
    // cakelog("Source Office [%d] package count is [%d]", source_office_index, source->offices[source_office_index].packages_count);
    // cakelog("Target Office [%d] package count is [%d]", target_office_index, target->offices[target_office_index].packages_count);

    int loop_counter;

    int target_min_weight = target->offices[target_office_index].min_weight;
    int target_max_weight = target->offices[target_office_index].max_weight;

    // cakelog("Target Office [%d] min weight is [%d] and max weight is [%d]", target_office_index, target_min_weight, target_max_weight);

    package* returned_queue;
    ssize_t returned_queue_size = 0;

    package* new_target_queue;
    ssize_t new_target_queue_size = 0;

    // Add all current packages in target queue to new queue
    // cakelog("Preserving current packages from target Office [%d] to new queue", source_office_index);
    for(loop_counter=0; loop_counter < target->offices[target_office_index].packages_count; loop_counter++) {

        package p = target->offices[target_office_index].packages[loop_counter];
        // cakelog("\tCopying package [%s] with weight [%d] from list", p.id, p.weight);

        new_target_queue_size = add_package_to_queue(&new_target_queue, new_target_queue_size, p);
    }

    // cakelog("New target office queue size is [%d]", new_target_queue_size);
    
    // Distribute between the two queues
    for(loop_counter=0; loop_counter < source->offices[source_office_index].packages_count; loop_counter++) {

        package p = source->offices[source_office_index].packages[loop_counter];
        // cakelog("Pulled package [%s] from source package queue with weight [%d]", p.id, p.weight);

        if (p.weight >= target_min_weight && p.weight <= target_max_weight) {
            new_target_queue_size = add_package_to_queue(&new_target_queue, new_target_queue_size, p);
            // cakelog("\tAdded to target delivery queue");
            // cakelog("\tTarget delivery queue size is now [%d]", new_target_queue_size);
        }
        else {
            // cakelog("Package doesn't meet weight requirements, adding to return queue");
            returned_queue_size = add_package_to_queue(&returned_queue, returned_queue_size, p);
            // cakelog("\tAdded to return delivery queue");
            // cakelog("\tReturn delivery queue size is now [%d]", returned_queue_size);
        }
    }

    // cakelog("New target queue length: [%d]", new_target_queue_size);
    for (int j=0; j<new_target_queue_size; j++) {
        // cakelog("Package id: [%s]", new_target_queue[j].id);
    }

    // Now swap out queues
    package* target_temp = target->offices[target_office_index].packages;
    target->offices[target_office_index].packages = new_target_queue;
    target->offices[target_office_index].packages_count = new_target_queue_size;
    free(target_temp);

    package* source_temp = source->offices[source_office_index].packages;
    source->offices[source_office_index].packages = returned_queue;
    source->offices[source_office_index].packages_count = returned_queue_size;
    free(source_temp);

}

// Misread this in the earlier question!
town town_with_most_packages(town* towns, int towns_count) {
    
    town max_town;
    int max_parcels = 0;
    int total_packages;

    for (int t=0; t<towns_count; t++) {
        total_packages = 0;
        for (int p=0; p<towns[t].offices_count; p++) {
            total_packages += towns[t].offices[p].packages_count;     
        }
        if (total_packages > max_parcels) {
            max_parcels = total_packages;
            max_town = towns[t];
        }
    }

    return max_town;
}
town* find_town(town* towns, int towns_count, char* name) {

    for (int t=0; t<towns_count; t++) {
        if (strcmp(name, towns[t].name)==0) {
            return &towns[t];
        }
    }
    return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
