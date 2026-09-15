#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort_digit(int *arr, int lastIndex, int exp){
    int counting_list[10] = {0};
    int *sorted = malloc(sizeof(int)*(lastIndex+1));

    for(int i = 0 ; i <= lastIndex ; i++){
        int digit = (arr[i]/exp) % 10;

        counting_list[digit]++;
    }

    for(int i = 1 ; i < 10 ; i++){
        counting_list[i] = counting_list[i-1] + counting_list[i];
    }

    for(int i = lastIndex ; i >= 0 ; i--){
        int digit = (arr[i]/exp) % 10;

        sorted[counting_list[digit]-1] = arr[i];
        counting_list[digit]--;
    }

    for(int i = 0 ; i <= lastIndex ; i++){
        arr[i] = sorted[i];
    }

    free(sorted);
    return;
}

void radix_sort(int *arr, int lastIndex){
    int MAX = getMax(arr, lastIndex);
    int exp = 1;

    while(MAX){
        counting_sort_digit(arr, lastIndex, exp);

        exp = exp*10;
        MAX = MAX/10;
    }
}