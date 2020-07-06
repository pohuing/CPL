#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "../lib/sort.h"
#include "../lib/file.h"

#define SORT_APPENDIX "-sort"
// Handling Windows specific path length restrictions
#ifndef _MAX_PATH
#define _MAX_PATH 260
#endif

void ui_start(){
    int submenu;
    while (true)
    {
    printf("Nummer angeben um option zu wählen\n");
    printf("\t1: Eigene Zahlen\n"
    "\t2: Von unsortiert.txt laden\n"
    "\t3: Arithmetisches Mittel von 1000-10_000"
    );
        int _ = scanf("%d", &submenu);
        switch (submenu)
        {
        case 1:
            _ui_custom_numbers();
            break;
        case 2:
            _ui_load_unsorted();
            break;
        case 3:
            _ui_bench();
            break;
        default:
            printf("Bitte Zahl von 1-3 Angeben\n");
            break;
        }
    }
    
}

void _ui_custom_numbers(){
    Data data;
    printf("Enter size of number set\n");
    data.size = _ui_get_size_t();
    data_instantiate(data.size, &data);
    printf("Enter values\n");
    for (size_t i = 0; i < data.size; i++)
    {
        printf("%zu:", i);
        int value = _ui_get_num();
        if(!data_set(&data, i, value)){
            printf("Error setting value, aborting");
            return;
        }
    }
    long swaps, comparisons;
    sort(&data, &swaps, &comparisons);
    data_print(&data);
    data_delete(&data);
    #ifdef COLLECT_STATS
    printf("Used %ld swaps and %ld comparisons\n", swaps, comparisons);
    #endif
}

void _ui_load_unsorted(){
    Data data;
    char path[_MAX_PATH - sizeof(SORT_APPENDIX)];
    char target_path[_MAX_PATH];
    long swaps, comparisons;
    do printf("Enter a path to load from ");
    while(!scanf("%s", path));
    if (file_load(&data, path))
    {
        sort(&data, &swaps, &comparisons);
        #ifdef COLLECT_STATS
        printf("Used %ld swaps and %ld comparisons", swaps, comparisons);
        #endif
        strcpy(target_path, path);
        strcat(target_path, SORT_APPENDIX);
        if(!file_store(&data, target_path))
            printf("ERR: Failed to save file to path: %s", target_path);
    }else
        printf("Failed to load file");
}

void _ui_bench(){
    int count;
    printf("How many repeats per step? ");
    while(!scanf("%d", &count));
    FILE* filepoint = fopen("Ergebnisse.txt", "w+");
    if (!filepoint)
    {
        printf("ERR: Failed to open or create file \"Ergebnisse.txt\" aborting");
        return;
    }
    fprintf(filepoint, "groesse, mit_swaps, mit_vergl\n");
    for (int factor = 1; factor <= 10; factor++)
    {
        long swaps, comparisons;
        unsigned long long total_swaps = 0, total_comparisons = 0;
        for (size_t i = 0; i < count; i++)
        {
            Data data;
            printf("Starting sorts for %d000\n", factor);
            data_generate(factor * 1000, &data);
            sort(&data, &swaps, &comparisons);
            total_swaps += swaps;
            total_comparisons += comparisons;
            #ifdef COLLECT_STATS
                printf("Swaps: %ld Comparisons: %ld\n", swaps, comparisons);
            #endif
            data_delete(&data);
        }
        fprintf(filepoint, "%d %llu %llu\n",
            factor * 1000,
            total_swaps/100,
            total_comparisons/100);
    }
    fclose(filepoint);
}

int _ui_get_num(){
    char buffer[128];
    int num = 0;
    while(!(num = atoi(buffer))){
        printf("Enter a number only: ");
        fgets(buffer, 128, stdin);
    }
    return num;
}

size_t _ui_get_size_t(){
    char buffer[128];
    size_t num = 0;
    while(!(num = strtoull(buffer, NULL, 10))){
        printf("Enter a number only: ");
        fgets(buffer, 128, stdin);
    }
    return num;
}