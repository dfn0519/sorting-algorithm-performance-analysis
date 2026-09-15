//Bubble sort for ascending order with worst case is O(n^2)
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int lastIndex){
    if(arr == NULL || lastIndex < 1){
        return;
    }

    int tmp;
    for(int i = lastIndex ; i > 0 ; i--){
        for(int j = 0 ; j < i ; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp; 
            }
        }
    }
    return;
}