#include "sort.h"

void sort(Data* data, long* swaps, long* comparisons){
    *swaps = 0;
    *comparisons = 0;
    for (size_t head = 0; head < data->size; head++)
    {
        size_t reverse_head = head;
        while (reverse_head && data->data[reverse_head - 1] > data->data[reverse_head])
        {
            data_swap(reverse_head - 1, reverse_head, data);
            #ifdef COLLECT_STATS
                (*swaps)++;
                (*comparisons)++;
            #endif
            reverse_head--;
        }
        #ifdef COLLECT_STATS
        // Case when comparison was !> but still performed
        if(reverse_head)
            (*comparisons)++;
        #endif
    }
}