#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    // Initialise total_number_of_books;
    //cakelog("Allocating [%d] shelves in total_number_of_books", total_number_of_shelves);
    total_number_of_books = calloc(total_number_of_shelves, sizeof(int));

    // Initialise total_number_of_pages;
    //cakelog("Allocating [%d] shelves in total_number_of_pages", total_number_of_shelves);
    total_number_of_pages = calloc(total_number_of_shelves, sizeof(int*));

    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);

            // Place x page book at end of shelf y
            //cakelog("Request to put book with [%d] pages at end of [%d] shelf", y, x);

            if (total_number_of_books[x] == 0) {
                //cakelog("First book on shelf [%d], allocating space.",x);
                total_number_of_pages[x] = malloc(sizeof(int));
                total_number_of_pages[x][0] = y;
                total_number_of_books[x] = 1;
                //cakelog("Added book with [%d] pages to shelf [%d]", y, x);
            }
            else {
                //cakelog("Total number of books already on shelf [%d] is [%d]",x, total_number_of_books[x]);
                //cakelog("Executing: realloc(total_number_of_pages[%d], total_number_of_books[%d]*sizeof(int)",x,x);
                total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x]*sizeof(int)+1);
                total_number_of_pages[x][total_number_of_books[x]]=y;
                total_number_of_books[x] = (total_number_of_books[x])+1;  // <- This this might have been the error.
            }

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}