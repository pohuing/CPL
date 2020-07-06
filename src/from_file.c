#include "lib/file.h"
#include "lib/data.h"
#include "lib/sort.h"

int main(){
    Data data;
    file_load(&data, "./unsortiert.txt");
    sort(&data, NULL, NULL);
    file_store(&data, "sortiert.txt");
    data_delete(&data);
    return 0;
}