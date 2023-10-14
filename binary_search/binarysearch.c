#include<stdio.h>
#include<string.h>
#include "binarysearch.h"

int binarySearch(WordEntry arr[], int low, int high, char x[])
{
     while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(arr[mid].word, x);
        if (cmp == 0) {
            return mid; // Word found
        } else if (cmp < 0) {
            low= mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Word not found
 
    // If we reach here, then element was not present
   // return -1;
}