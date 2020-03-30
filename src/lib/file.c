#include <stdio.h>
#include "data.h"

// Initializes a Data from a file in the format of unsortiert.txt
int file_load(Data* data, char path[]){
    FILE* filepoint = fopen(path, "r");
    if (filepoint)
    {
        int scan_err = fscanf(filepoint, "%ud", &data->size);
        data->data = malloc(data->size * sizeof(int));
        for (int i = 0; i < data->size; i++)
        {
            fscanf(filepoint, "%d", &data->data[i]);
        }
        fclose(filepoint);
    }
}