#include "ui.h"
#include "data.h"
#include "sort.h"

void ui_start(){}
void ui_show_menu(){}
void _ui_bench(){
    for (int factor = 1; factor <= 10; factor++)
    {
        long swaps, comparisons;
        for (size_t i = 0; i < 100; i++)
        {
            Data data;
            printf("Starting sorts for %d000\n", factor);
            data_generate(factor * 1000, &data);
            sort(&data, &swaps, &comparisons);
            #ifdef COLLECT_STATS
                printf("Swaps: %ld Comparisons: %ld\n", swaps, comparisons);
            #endif
            data_delete(&data);
        }

    }
}