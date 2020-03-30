#include <stdio.h>
#include "data.h"

int file_load(Data* data, char path[]){
    FILE* filepoint;
    int err = fopen_s(&filepoint, path, "r");
    if (err)
    {
        int scan_err = fscanf_s(filepoint, "%d\n", &data->size);
        for (size_t i = 0; i < data->size; i++)
        {
            fscanf_s(filepoint, "%d", &data->data[i]);
        }
        fclose(filepoint);
    }
}