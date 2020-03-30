#if !defined(DATA_H)
#define DATA_H
#include <stdlib.h>

typedef struct {
    size_t size;
    int* data;
} Data;

void data_generate(size_t size, Data* outData);
void data_delete(Data* data);


#endif // data
