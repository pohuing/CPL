#include <stdio.h>
#include "lib/sort.h"
#include "lib/file.h"

int main(){
    Data data;
    file_load(&data, "unsortiert.txt");
    data_print(&data);
    printf("\n");
    sort(&data);
    data_print(&data);
    printf("\n");


    return 0;
}