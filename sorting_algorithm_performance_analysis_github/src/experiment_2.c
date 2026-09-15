#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "datasets/generatearray.h"
#include "sorting/sort.h"
#include "benchmark/benchmark.h"


typedef struct{
    char *sortingName;
    void (*sort)(int *, int);
} SortingAlgorithm;


int main(){
    FILE *fp = fopen("experiment2.csv", "w");

    if(fp == NULL){
        fprintf(stderr, "file opening failed.\n");
        return 1;
    }


    fprintf(fp, "Algorithm,Size,ValueRange,Time\n");

    int size = 100000;

    int valueRange[] =
    {
        10,
        100,
        1000,
        10000,
        100000,
        500000,
        1000000
    };

    SortingAlgorithm sorting[] =
    {
        {"Merge", merge_sort_package},
        {"Quick", quick_sort_package},
        {"Radix", radix_sort},
        {"Heap", heap_sort},
        {"Counting", counting_sort}
    };

    int len_valueRange = sizeof(valueRange) / sizeof(valueRange[0]);


    int len_sorting = sizeof(sorting) / sizeof(sorting[0]);


    int *original = (int *)calloc(size, sizeof(int));

    if(original == NULL){fprintf(stderr, "array allocation failed.\n");
        fclose(fp);
        return 1;
    }

    for(int i = 0 ; i < len_valueRange ; i++){
        generate_random_range(original, size, valueRange[i]);

        for(int j = 0 ; j < len_sorting ; j++){
            double t = benchmark_average(sorting[j].sort, original, size, 10, sorting[j].sortingName);

            printf(
                "%s | size=%d | range=%d | %.6f sec\n",
                sorting[j].sortingName,
                size,
                valueRange[i],
                t
            );

            fprintf(
                fp, "%s,%d,%d,%.6f\n",
                sorting[j].sortingName,
                size,
                valueRange[i],
                t
            );
        }
    }

    free(original);

    fclose(fp);

    return 0;
}