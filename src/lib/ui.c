#include <stdio.h>
#include "ui.h"
#include "data.h"
#include "sort.h"
#include "file.h"

void ui_start(){
    int submenu;
    while (true)
    {
    printf("Nummer angeben um option zu wählen\n");
    printf("\t1: Eigene Zahlen\n"
    "\t2: Von sortiert.txt laden\n"
    "\t3: Arithmetisches Mittel von 1000-10_000"
    );
        scanf("%d", &submenu);
        switch (submenu)
        {
        case 1:
            _ui_custom_numbers();
            break;
        case 2:
            _ui_load_unsorted();
        case 3:
            _ui_bench();
        default:
            printf("Bitte Zahl von 1-3 Angeben\n");
            break;
        }
    }
    
}

void _ui_custom_numbers(){
    Data data;
    printf("Enter size of number set\n");
    scanf("%lu", &data.size);
    data_instantiate(data.size, &data);
    printf("Enter values\n");
    for (size_t i = 0; i < data.size; i++)
    {
        printf("%lu:", i);
        int value = 0;
        scanf("%d", &value);
        if(!data_set(i, &data, value)){
            printf("Error setting value, aborting");
            return;
        }
    }
    long swaps, comparisons;
    sort(&data, &swaps, &comparisons);
    data_print(&data);
    #ifdef COLLECT_STATS
    printf("Used %ld swaps and %ld comparisons", swaps, comparisons);
    #endif
}

void _ui_load_unsorted(){
    Data data;
    long swaps, comparisons;
    file_load(&data, "unsortiert.txt");
    sort(&data, &swaps, &comparisons);
}

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