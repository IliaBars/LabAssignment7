#include <stdio.h>

void swap(int *a, int *b, int swaps[], int *swapsTotal) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps[*b]++;
    swaps[*a]++;
    (*swapsTotal)++;
}

void bubbleSort(int arr[], int n, int swaps[], int *swapsTotal) {
    int i, j;
    *swapsTotal = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1], swaps, swapsTotal);
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[], int *swapsTotal) {
    int i, j, min_idx;
    *swapsTotal = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx], swaps, swapsTotal);
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swaps1[100] = {0};
    int swaps2[100] = {0};
    int swapsTotal1 = 0;
    int swapsTotal2 = 0;

    bubbleSort(array1, 9, swaps1, &swapsTotal1);
    printf("array1:\n");
    for(int i = 0; i < 9; i++) {
        printf("%d: # of times %d is swapped\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total # of swaps: %d\n\n", swapsTotal1);

    selectionSort(array2, 9, swaps2, &swapsTotal2);
    printf("array2:\n");
    for(int i = 0; i < 9; i++) {
        printf("%d: # of times %d is swapped\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total # of swaps: %d\n", swapsTotal2);

    return 0;
}
