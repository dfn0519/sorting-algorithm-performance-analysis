#include <stdio.h>
#include <stdlib.h>
#include "../sorting/sort.h"
#include "../datasets/generatearray.h"
#include <time.h>
#include "benchmark.h"
#include <string.h>

double benchmark(void (*sort)(int *arr, int lastIndex), int *arr, int lastIndex, char *sortingName){
    clock_t start, end;

    start = clock();
    sort(arr, lastIndex);
    end = clock();

    double time = (double)(end-start)/CLOCKS_PER_SEC;

    printf("%s time = %f\n", sortingName, time);
    return time;
}

double benchmark_average(void (*sort)(int *arr, int last_index), int *original, int arrSize, int repeat, char *sortingName){
    clock_t start, end;

    int *test = (int *)calloc(arrSize, sizeof(int));
    
    if(test == NULL){
        fprintf(stderr, "array test allocation failed.\n");
        return 1;
    }

    double elaspe = 0;
    
    for(int i = 0 ; i < repeat ; i++){
        memcpy(test, original, sizeof(int)*arrSize);
        
        start = clock();
        sort(test, arrSize-1);
        end = clock();

        testArray(test, arrSize-1, sortingName, arrSize);

        elaspe += (double)(end - start) / CLOCKS_PER_SEC;
    }

    free(test);
    elaspe = elaspe/repeat;

    return elaspe;
}