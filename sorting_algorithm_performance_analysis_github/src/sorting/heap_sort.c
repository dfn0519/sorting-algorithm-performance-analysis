//heap sort for ascending order with worst case is O(nlogn)
//選一個插入到最合適的位置
//思路:建立max heap在將root與最後一位互換

#include <stdio.h>
#include <stdlib.h>

void heapify(int *arr, int heapLastIndex, int fixindex){
    int left = fixindex*2+1;
    int right = fixindex*2+2;
    
    if(left > heapLastIndex && right > heapLastIndex){
        return;
    }

    int largest = fixindex;
    int tmp;

    if(left <= heapLastIndex && arr[left] > arr[largest]){
        largest = left;
    }

    if(right <= heapLastIndex && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != fixindex){
        tmp = arr[largest];
        arr[largest] = arr[fixindex];
        arr[fixindex] = tmp;

        heapify(arr, heapLastIndex, largest);
    }
}

void buildMaxHeap(int *arr, int heapLastIndex){
    for(int i = (heapLastIndex-1)/2 ; i >= 0 ; i--){
        heapify(arr, heapLastIndex, i);
    }
}

void heap_sort(int *arr, int last_index){
    int tmp;
    
    buildMaxHeap(arr, last_index);
    
    tmp = arr[0];
    arr[0] = arr[last_index];
    arr[last_index] = tmp;
    
    for(int i = last_index-1 ; i > 0 ; i--){
        heapify(arr, i, 0);

        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
    }
}