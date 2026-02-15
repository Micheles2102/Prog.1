/*
 * COMPLESSITÀ BUBBLE SORT:
 * Tempo: Peggiore O(n^2), Migliore O(n) [con ottimizzazione], Medio O(n^2)
 * Spazio: O(1) [in-place]
 *
 * COMPLESSITÀ INSERTION SORT:
 * Tempo: Peggiore O(n^2), Migliore O(n), Medio O(n^2)
 * Spazio: O(1) [in-place]
 */

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // Se non ci sono stati scambi, l'array è già ordinato
        if (swapped == 0) break;
    }
}

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(data1) / sizeof(data1[0]);
    
    printf("Array originale: ");
    print_array(data1, n1);
    
    bubble_sort(data1, n1);
    printf("Bubble Sort applicato: ");
    print_array(data1, n1);

    int data2[] = {12, 11, 13, 5, 6};
    int n2 = sizeof(data2) / sizeof(data2[0]);
    
    printf("\nArray originale: ");
    print_array(data2, n2);
    
    insertion_sort(data2, n2);
    printf("Insertion Sort applicato: ");
    print_array(data2, n2);

    return 0;
}
