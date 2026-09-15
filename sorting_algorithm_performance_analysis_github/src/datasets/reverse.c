#include <stdio.h>
#include <stdlib.h>
#include "generatearray.h"

void generate_reverse(int *arr, int n){
    for(int i = n-1, k = 0 ; i >= 0 ; i--, k++){
        arr[k] = i;
    }
    return;
}