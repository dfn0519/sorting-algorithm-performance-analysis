#include <stdio.h>
#include <stdlib.h>
#include "generatearray.h"

void generate_sorted(int *arr, int n){
    for(int i = 0 ; i < n ; i++){
        arr[i] = i;
    }
    return;
}