#include <stdio.h>
#include <stdlib.h>
#include "generatearray.h"

void generate_duplicate(int *arr, int n){
    for(int i = 0 ; i < n ; i++){
        arr[i] = rand()%10;
    }
    return;
}