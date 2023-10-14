#include "quickSort.h"

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    // Choosing the pivot
    int pivot = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int x = (low - 1);
 
    for (int y = low; y <= high - 1; y++) {
 
        // If current element is smaller than the pivot
        if (arr[y] < pivot) {
 
            // Increment index of smaller element
            x++;
            swap(&arr[x], &arr[y]);
        }
    }
    swap(&arr[x + 1], &arr[high]);
    return (x + 1);
}

void qckSort(int arr[], int low, int high)
{
    if (low < high) {
 
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        qckSort(arr, low, pi - 1);
        qckSort(arr, pi + 1, high);
    }
}