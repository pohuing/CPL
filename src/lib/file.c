#include <stdio.h>
#include "data.h"

// Initializes a Data from a file in the format of unsortiert.txt
int file_load(Data* data, char path[]){
    FILE* filepoint = fopen(path, "r");
    if (filepoint)
    {
        int scan_err = fscanf(filepoint, "%lu", &data->size);
        data->data = malloc(data->size * sizeof(int));
        for (int i = 0; i < data->size; i++)
        {
            int _ = fscanf(filepoint, "%d", &data->data[i]);
        }
        fclose(filepoint);
        return 1;
    }
    #ifdef LOGGING
    printf("ERR: failed opening file %s", path);
    #endif
    return -1;
}

// Creates file "path", truncating existing contents
// returns 1 if success -1 if filehandle failed to be created
int file_store(Data* data, char path[]){
    FILE* filepoint = fopen(path, "w+");
    if(filepoint){
        fprintf(filepoint, "%lu\n", data->size);
        for (size_t i = 0; i < data->size; i++)
        {
            int value;
            if(data_get(data, i, &value))
                fprintf(filepoint, "%d ", value);
        }
    }else
    {
        #ifdef LOGGING
        printf("ERR: failed to open file for writing %s", path);
        #endif
        return -1;
    }
    
}