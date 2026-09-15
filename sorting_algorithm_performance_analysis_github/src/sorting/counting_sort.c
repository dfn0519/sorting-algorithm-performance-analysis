#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *arr, int lastIndex){
    int MAX = getMax(arr, lastIndex);
    int *counting_list = (int *)calloc(MAX+1, sizeof(int));

    for(int i = 0 ; i <= lastIndex ; i++){
        counting_list[arr[i]]++;
    }

    int index = 0;

    for(int i = 0 ; i <= MAX ; i++){
        while(counting_list[i]){
            arr[index] = i;
            index++; counting_list[i]--;
        }
    }

    free(counting_list);
}