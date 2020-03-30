#if !defined(DATA_H)
#define DATA_H
#include <stdlib.h>

typedef struct Data{
    size_t size;
    int* data;
} Data;

void data_generate(size_t size, Data* outData);
void data_delete(Data* data);
int data_get(size_t index, Data* data, int* out);
int swap(size_t index1, size_t index2, Data* data);


#endif // data
