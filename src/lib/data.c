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
        int temp = outData->data[rand_1];
        outData->data[rand_1] = outData->data[rand_2];
        outData->data[rand_2] = temp;
    }
}

void data_delete(Data* data){
    free(data->data);
}

// returns if a get was successfull
int data_get(size_t index, Data* data, int* out){
    if (index < data->size)
    {
        *out = data->data[index];
        return 0;
    }else
    {
        return -1;
    }
}