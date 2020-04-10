#include "data.h"
#include <stdio.h>
#include <stdlib.h>

// Fills a Data pointer with new randomized data
void data_generate(size_t size, Data* outData){
    outData->size = size;
    outData->data = malloc(size * sizeof(int));
    for (size_t i = 0; i < size; i++)
    {
        outData->data[i] = i;
    }
    //shuffle size times
    for (size_t counter = 0; counter < size; counter++)
    {
        size_t rand_1 = rand() % size;
        size_t rand_2 = rand() % size;
        data_swap(outData, rand_2, rand_1);
    }
}

void data_instantiate(size_t size, Data* outData){
    outData->size = size;
    outData->data = malloc(outData->size * sizeof(int));
}

void data_delete(Data* data){
    data->size = 0;
    free(data->data);
    data->data = NULL;
}

int data_get(Data *data, size_t index, int *out) {
    if (index < data->size)
    {
        *out = data->data[index];
        return 1;
    }else
    {
        #ifdef LOGGING
            printf("ERR: trying to access index %lu of %p max size %lu", index, (void*)data, data->size);
        #endif
        return -1;
    }
}

int data_set(Data *data, size_t index, int value) {
    if (index < data->size)
    {
        data->data[index] = value;
        return 1;
    }else
    {
        #ifdef LOGGING
        printf("ERR: trying to set index %lu of data %p max size %lu", index, (void*)data, data->size);
        #endif
        return -1;
    }
}

// returns 1 if swap was successful
int data_swap(Data *data, size_t index2, size_t index1) {
    if (index1 < data->size && index2 < data->size)
    {
        int temp = data->data[index1];
        data->data[index1] = data->data[index2];
        data->data[index2] = temp;
        return 1;
    }else
    {
        #ifdef LOGGING
            printf("ERR: trying to swap indices %lu %lu of data %p max size %lu", index1, index2, (void*)data, data->size);
        #endif
        return -1;
    }  
}

void data_print(Data* data){
    for (size_t i = 0; i < data->size; i++)
    {
        printf("%d ", data->data[i]);
    }
}