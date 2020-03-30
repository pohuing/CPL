#include "data.h"
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
        int rand_1 = rand() % size;
        int rand_2 = rand() % size;
        data_swap(rand_1, rand_2, outData);
    }
}

void data_delete(Data* data){
    free(data->data);
}

// returns 1 if a get was successfull
int data_get(size_t index, Data* data, int* out){
    if (index < data->size)
    {
        *out = data->data[index];
        return 1;
    }else
    {
        return -1;
    }
}

// returns 1 if swap was successfull
int data_swap(size_t index1, size_t index2, Data* data){
    if (index1 < data->size && index2 < data->size)
    {
        int temp = data->data[index1];
        data->data[index1] = data->data[index2];
        data->data[index2] = temp;
        return 1;
    }else
    {
        return -1;
    }  
}

void data_print(Data* data){
    for (size_t i = 0; i < data->size; i++)
    {
        printf("%d ", data->data[i]);
    }
}