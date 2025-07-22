#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */

int main()
{
    int total_number_of_shelves; 
    scanf("%d", &total_number_of_shelves);

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    //making shelves 
    int **total_number_of_pages = (int**) malloc(sizeof(int*) * total_number_of_shelves);

    //making sure shelves are empty
    for(int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_pages[i] = NULL;
    }

    //xth index gives no. of books in the xth shelve
    int *total_number_of_books = (int*) malloc(sizeof(int) * total_number_of_shelves);
    //there will be 0 books in each shelve initially
    for(int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_books[i] = 0;
    }

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);

            //if there is atleast one book in xth shelve, then resize the shelve to put a new book
            if(total_number_of_books[x]) {
                //put a new book in the xth shelve
                total_number_of_pages[x] = (int*) realloc(total_number_of_pages[x], 
                                                   sizeof(int) * (total_number_of_books[x] + 1)
                                                   );
                //increase count for new book in xth shelve
                total_number_of_books[x]++;

                int new_book_index = total_number_of_books[x] - 1;
                //put y pages in the new book
                total_number_of_pages[x][new_book_index] = y;
            } else { 
                //put the first book in xth shelve
                total_number_of_pages[x] = (int*) malloc(sizeof(int));
                total_number_of_books[x]++;
                //put y pages in the fist book
                total_number_of_pages[x][0] = y;
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
