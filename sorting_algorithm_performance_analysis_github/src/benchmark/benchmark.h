#ifndef BENCHMARK_H
#define BENCHMARK_H

double benchmark(void (*sort)(int *arr, int lastIndex), int *arr, int lastIndex, char *sortingName);
double benchmark_average(void (*sort)(int *arr, int last_index), int *original, int arrSize, int repeat, char *sortingName);

#endif