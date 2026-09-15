// quick sort for ascending order
//pivot從中間選 選最旁邊會stack overflow
#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int start, int end){
    int pivot = arr[(start + end) / 2];

    int left = start;
    int right = end;

    while(left <= right){

        while(arr[left] < pivot){
            left++;
        }

        while(arr[right] > pivot){
            right--;
        }

        if(left <= right){
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;

            left++;
            right--;
        }
    }

    return left;
}

void quick_sort(int *arr, int start, int end){

    if(start < end){

        int pivotIndex = partition(arr, start, end);

        quick_sort(arr, start, pivotIndex - 1);
        quick_sort(arr, pivotIndex, end);
    }
}

void quick_sort_package(int *arr, int lastIndex){
    //printf("quick start\n");

    quick_sort(arr, 0, lastIndex);

    //printf("quick end\n");
}