#include <stdio.h>
#include <stdlib.h>
#include "generatearray.h"

void generate_almost_sorted(int *arr, int n){
    for(int i = 0 ; i < n ; i++){
        arr[i] = i;
    }

    for(int i = 0 ; i < n/20 ; i++){
        int a = rand()%n;
        int b = rand()%n;

        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
    return;
}
