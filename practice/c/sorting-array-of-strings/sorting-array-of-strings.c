
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int result = strcmp(a, b);
    if ( result > 0) {
        result = -1;
    }
    else if (result <0) {
        result = 1;
    }
    else
    {
        result = 0;
    }
    
    return result;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {

    int distinct_chars_in_a = 0;
    int distinct_chars_in_b = 0;
    int a_len = strlen(a);
    int b_len = strlen(b);
    int i;

    char characters_a[256];
    char characters_b[256]; 

    //Set to zero
    for(i=0; i<256; i++) {
        characters_a[i] = 0;
        characters_b[i] = 0;
    }

    //Get distinct chars in a string
    for (i=0; i<a_len; i++) {
        if(characters_a[(int)a[i]] == 0) {
            characters_a[(int)a[i]] = 1; 
            distinct_chars_in_a++;        
        }
    }
    //cakelog("Distinct chars in a: %d", distinct_chars_in_a);

    for (i=0; i<b_len; i++) {
        if(characters_b[(int)b[i]] == 0) {
            characters_b[(int)b[i]] = 1;
            distinct_chars_in_b++;
        }     
    }    
    //cakelog("Distinct chars in b: %d", distinct_chars_in_b);

    if(distinct_chars_in_a < distinct_chars_in_b) {
        return 0;
    }
    else if(distinct_chars_in_a > distinct_chars_in_b) {
        return  1;
    }
    else {  
        return lexicographic_sort(a, b);  
    }     
}

int sort_by_length(const char* a, const char* b) {

    int a_len, b_len;
    a_len = strlen(a);
    b_len = strlen(b);

    if (a_len < b_len) {
        return 0;
    }
    else if (a_len > b_len) {
        return 1;
    }
    else {
        return lexicographic_sort(a, b);
    }     

}
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int success;
    int i;

    // success = initialise_cakelog("string-search");
    // if (success != 0) {
    //     printf("error initialising cakelog.\n");
    //     exit(EXIT_FAILURE);
    // }

    // char strings[][1000] = {"wkue", "qoigg", "sbv", "fekggggls"};

    // cakelog("Unsorted Array:");
    // for(i=0; i<4; i++) {
    //     cakelog("%d: %s", i, strings[i]);
    // }

    // First attempt - thought there would be clashes if I kept assigning pointers
    // int sorted = 1;
    // char temp[1000];
    // while(sorted == 1) {
    //     sorted = 0;
    //     for (i=0; i<(len-1); i++) {
    //         // cakelog("Comparing '%s' to '%s'", strings[i], strings[i+1]);
    //         if (cmp_func(arr[i], arr[i+1]) > 0) {
    //             // cakelog("%s is less than %s", strings[i], strings[i+1]);
    //             strcpy(temp, arr[i+1]);
    //             strcpy(arr[i+1], arr[i]);
    //             strcpy(arr[i], temp);
    //             sorted = 1;
    //         }
    //     }
    // }

    int sorted = 1;
    char* temp;
    while(sorted == 1) {
        sorted = 0;
        for (i=0; i<(len-1); i++) {
            // cakelog("Comparing '%s' to '%s'", strings[i], strings[i+1]);
            if (cmp_func(arr[i], arr[i+1]) > 0) {
                // cakelog("%s is less than %s", strings[i], strings[i+1]);
                temp = arr[i+1];
                // cakelog("Copied %s to temp", temp);
                arr[i+1] = arr[i];
                // cakelog("Copied %s to strings[i+1]", strings[i+1]);
                arr[i] = temp;
                sorted = 1;
            }
        }
    }
}
