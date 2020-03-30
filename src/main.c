#include <stdio.h>
#include "lib/sort.h"
#include "lib/file.h"
#include "lib/ui.h"

int main(){
    Data data;
    // file_load(&data, "unsortiert.txt");
    // printf("Comparisons: %d", sort(&data));
    _ui_bench();
    printf("\n");
    return 0;
}