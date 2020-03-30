#include <stdio.h>
#include "lib/data.h"
#include "lib/sort.h"

int main(){
    Data data;
    data_generate(10, &data);
    data_print(&data);
    printf("\n");
    sort(&data);
    data_print(&data);
    printf("\n");
    return 0;
}