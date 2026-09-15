#include <stdio.h>
#include <stdlib.h>
#include "generatearray.h"

void generate_random(int *arr, int n){
    for(int i = 0 ; i < n ; i++){
        arr[i] = rand();
    }
    return;
}

void generate_random_range(int *arr, int n, int range){
    for(int i = 0 ; i < n ; i++){
        arr[i] = rand() % range;
    }
    
    if(n >= 2){
        arr[0] = 0;
        arr[1] = range - 1;
    }

    return;
}