#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int getMax(int *arr, int lastIndex){
    int MAX = arr[0];
    
    for(int i = 0 ; i <= lastIndex ; i++){
        if(MAX < arr[i]){
            MAX = arr[i];
        }
    }

    return MAX;
}

void testArray(int *arr, int lastIndex, char *sortingName, int arrSize){
    for(int i = 0 ; i < lastIndex ; i++){
        if(arr[i] > arr[i+1]){
            printf("wrong answer with %s in range %d\n", sortingName, arrSize);
            return;
        }
    }
    /*
    if(ok){
        printf("%s correct in range %d\n", sortingName, arrSize);
    }
    */
    return;
}