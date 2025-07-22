problem was in the malloc call for total_number_of_pages
int **total_number_of_pages = (int**) malloc(sizeof(int) * total_number_of_shelves);
but total_number_of_pages[x] is a pointer to int, therefore we need to use sizeof(int*) instead of sizeof(int).
int **total_number_of_pages = (int**) malloc(sizeof(int*) * total_number_of_shelves);
