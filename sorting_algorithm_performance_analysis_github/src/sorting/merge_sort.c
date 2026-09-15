//merge_sort for ascending order
#include <stdio.h>
#include <stdlib.h>


void merge(int *arr, int start, int mid, int end){
    int left = start,  right = mid+1;
    int array_size = end-start+1;
    int *swap = (int *)malloc(sizeof(int)*array_size);
    int swap_len = 0;
    
    while(left <= mid && right <= end){
        if(arr[left] < arr[right]){
            swap[swap_len] = arr[left];
            left++;
        }
        else{
            swap[swap_len] = arr[right];
            right++;
        }
        swap_len++;
    }

    while(left <= mid){
        swap[swap_len] = arr[left];
        swap_len++, left++;
    }

    while(right <= end){
        swap[swap_len] = arr[right];
        swap_len++, right++;
    }

    for(int i = 0, k = start ; i < array_size ; i++, k++){
        arr[k] = swap[i];
    }

    free(swap);
    return;
}

void merge_sort(int *arr, int start, int end){
    if(start == end){
        return;
    }

    int mid = (start+end)/2;
    
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);

    merge(arr, start, mid, end);
    return;
}

void merge_sort_package(int *arr, int lastIndex){
    merge_sort(arr, 0, lastIndex);
    return;
}
