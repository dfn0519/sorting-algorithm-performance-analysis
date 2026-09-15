//insertion sort for ascending order with worst case is O(n^2)
//選一個插入到最合適的位置

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int last_index){
    for(int insert_index = 1 ; insert_index <= last_index ; insert_index++){
        int current = arr[insert_index];
        int number = insert_index-1;

        while(number >= 0 && arr[number] > current){
            arr[number+1] = arr[number];
            number--;
        }

        arr[number+1] = current;
    }
    return;
}