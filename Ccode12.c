// HackerRank question for Dynamic allocation of arrays

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
    
    total_number_of_books = malloc(total_number_of_shelves * sizeof(int));          // Dynamic allocation of shelves
    for(int i = 0; i < total_number_of_shelves; i++)
       total_number_of_books[i] = NULL;
          
    total_number_of_pages = malloc(total_number_of_shelves * sizeof(int *));
    
    for(int i = 0; i < total_number_of_shelves; i++)
            total_number_of_pages[i] = NULL;
        
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;                          // x --> Shelf number,  y --> Number of pages
            scanf("%d %d", &x, &y);
            
            if(total_number_of_books[x])            // if condition is executed only from second book onwards
            {
              total_number_of_pages[x] = (int*)realloc(total_number_of_pages[x], (total_number_of_books[x]+1) * sizeof(int));
                //  Dynamically allocating each cell for every new book
              total_number_of_books[x]++;
              total_number_of_pages[x][total_number_of_books[x]-1] = y; 
            }
            
            else                                  //  this block is executed for every first book of the shelf
            {
                total_number_of_pages[x] = malloc(sizeof(int));
                total_number_of_books[x]++;
                total_number_of_pages[x][0] = y;
            }

        } else if (type_of_query == 2) {
            int x, y;                                          //  x --> Shelf number,  y --> Book index
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;                                            //  x --> Shelf index
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
