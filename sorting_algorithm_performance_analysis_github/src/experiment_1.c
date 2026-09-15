#include <stdio.h>
#include <stdlib.h>
#include "datasets/generatearray.h"
#include "sorting/sort.h"
#include "benchmark/benchmark.h"
#include <string.h>

typedef struct{
    char *name;
    void (*generate)(int *, int);
} DataGenerator;

typedef struct{
    char *sortingName;
    void (*sort)(int *, int);
} SortingAlgorithm;

void see(int *arr){
    int count = 0;

    for(int i = 0 ; i < 100 ; i++){
        if(count % 10 == 0){
            printf("\n");
        }

        printf("%d ", arr[i]);
        count++;
    }

    printf("\n");
}

int main(){

    FILE *fp = fopen("experiment1.csv", "w");

    fprintf(fp, "DataType,Algorithm,Size,Time\n");

    /*
        O(N^2) 演算法使用較小的 Size
    */
    int smallSizes[] =
    {
        1000,
        5000,
        10000,
        20000,
        50000
    };

    /*
        O(N log N) / O(N) 演算法可以使用較大的 Size
    */
    int largeSizes[] =
    {
        50000,
        100000,
        500000,
        1000000,
        5000000,
        10000000,
        50000000,
        100000000
    };
    
    DataGenerator generate[] = 
    {
        {"Random", generate_random},
        {"Reverse", generate_reverse},
        {"Sorted", generate_sorted},
        {"Almost Sorted", generate_almost_sorted}
    };

    /*
        O(N^2) 演算法
    */
    SortingAlgorithm slowSorting[] =
    {
        {"Bubble", bubble_sort},
        {"Selection", selection_sort},
        {"Insertion", insertion_sort}
    };

    /*
        效率較高的演算法
    */
    SortingAlgorithm fastSorting[] =
    {
        {"Merge", merge_sort_package},
        {"Quick", quick_sort_package},
        //{"Counting", counting_sort},
        {"Radix", radix_sort},
        {"Heap", heap_sort}
    };

    int len_smallSizes =sizeof(smallSizes) / sizeof(smallSizes[0]);

    int len_largeSizes = sizeof(largeSizes) / sizeof(largeSizes[0]);

    int len_generate = sizeof(generate) / sizeof(generate[0]);

    int len_slowSorting = sizeof(slowSorting) / sizeof(slowSorting[0]);

    int len_fastSorting = sizeof(fastSorting) / sizeof(fastSorting[0]);

    int *original;

    /*
        ========================================
        O(N^2) Sorting
        ========================================
    */

    for(int i = 0 ; i < len_smallSizes ; i++){

        original = (int *)calloc(smallSizes[i], sizeof(int));

        for(int k = 0 ; k < len_generate ; k++){

            generate[k].generate(original, smallSizes[i]);

            for(int j = 0 ; j < len_slowSorting ; j++){

                double t = benchmark_average(slowSorting[j].sort, original, smallSizes[i], 10, slowSorting[j].sortingName);

                printf(
                    "%s | %s | size=%d | %.6f sec\n",
                    generate[k].name,
                    slowSorting[j].sortingName,
                    smallSizes[i],
                    t
                );

                fprintf(
                    fp,
                    "%s,%s,%d,%.6f\n",
                    generate[k].name,
                    slowSorting[j].sortingName,
                    smallSizes[i],
                    t
                );
            }
        }

        free(original);
    }

    /*
        ========================================
        O(N log N) / O(N) Sorting
        ========================================
    */

    for(int i = 0 ; i < len_largeSizes ; i++){

        original = (int *)calloc(largeSizes[i], sizeof(int));

        for(int k = 0 ; k < len_generate ; k++){

            generate[k].generate(original, largeSizes[i]);

            for(int j = 0 ; j < len_fastSorting ; j++){

                double t = benchmark_average(fastSorting[j].sort, original, largeSizes[i], 10, fastSorting[j].sortingName);

                printf(
                    "%s | %s | size=%d | %.6f sec\n",
                    generate[k].name,
                    fastSorting[j].sortingName,
                    largeSizes[i],
                    t
                );

                fprintf(
                    fp,
                    "%s,%s,%d,%.6f\n",
                    generate[k].name,
                    fastSorting[j].sortingName,
                    largeSizes[i],
                    t
                );
            }
        }

        free(original);
    }

    fclose(fp);

    return 0;
}