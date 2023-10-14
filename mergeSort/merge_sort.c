// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int x, y, z;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (x = 0; x < n1; x++)
		L[x] = arr[l + x];
	for (y = 0; y < n2; y++)
		R[y] = arr[m + 1 + y];

	// Merge the temp arrays back into arr[l..r
	x = 0;
	y = 0;
	z = l;
	while (x < n1 && y < n2) {
		if (L[x] <= R[y]) {
			arr[z] = L[x];
			x++;
		}
		else {
			arr[z] = R[y];
			y++;
		}
		z++;
	}

	// Copy the remaining elements of L[],
	// if there are any
	while (x < n1) {
		arr[z] = L[x];
		x++;
		z++;
	}

	// Copy the remaining elements of R[],
	// if there are any
	while (y < n2) {
		arr[z] = R[y];
		y++;
		z++;
	}
}

// Function to print an array
void printArray(int X[], int size)
{
	int x;
	for (x = 0; x < size; x++)
		printf("%d ", X[x]);
	printf("\n");
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mrgSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mrgSort(arr, l, m);
		mrgSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

