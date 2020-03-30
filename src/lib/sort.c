#include "sort.h"

int sort(Data* data){
    long swaps = 0;
    for (size_t head = 0; head < data->size; head++)
    {
        size_t reverse_head = head;
        while (reverse_head && data->data[reverse_head - 1] > data->data[reverse_head])
        {
            data_swap(reverse_head - 1, reverse_head, data);
            #ifdef COUNT_SWAPS
            swaps++;
            #endif
            reverse_head--;
        }
    }
    return swaps;
}