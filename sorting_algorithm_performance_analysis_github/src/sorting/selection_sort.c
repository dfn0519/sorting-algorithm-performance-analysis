//selection sort for ascending order with worst case is O(n^2)
//選最初位置的數字 將後面的最小值與其互換

#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int last_index){
    
    for(int select = 0 ; select < last_index ; select++){
        int current = arr[select];
        int min = arr[select+1];
        int index = select+1;

        for(int k = select+1 ; k <= last_index ; k++){
            if(min > arr[k]){
                min = arr[k];
                index = k;
            }
        }

        if(current > min){
            arr[select] = min;
            arr[index] = current;
        }
    }
    return;
}