#ifndef SORT_H
#define SORT_H

#include <stddef.h>

int getMax(int *arr, int lastIndex);
void testArray(int *arr, int lastIndex, char *sortingName, int arrSize);

void bubble_sort(int *arr, int len);
void quick_sort(int *arr , int start, int end);
void merge_sort(int *arr, int start, int end);
void insertion_sort(int *arr, int last_index);
void selection_sort(int *arr, int last_index);
void heap_sort(int *arr, int last_index);
void radix_sort(int *arr, int lastIndex);
void counting_sort_digit(int *arr, int lastIndex, int exp);
void counting_sort(int *arr, int lastIndex);
void quick_sort_package(int *arr, int lastIndex);
void merge_sort_package(int *arr, int lastIndex);

#endif 