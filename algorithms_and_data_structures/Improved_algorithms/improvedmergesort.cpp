// C program to implement merge sort that works 
// in O(n) time in best case. 
#include <stdio.h> 
#include <stdlib.h> 

void merge(int* arr, int low, int mid, int high); 

void mergesort(int* arr, int low, int high) 
{ 
	if (low < high) { 
		int mid = (low + high) / 2; 
		mergesort(arr, low, mid); 
		mergesort(arr, mid + 1, high); 

		// This is where we optimize for best 
		// case. 
		if (arr[mid] > arr[mid + 1]) 
			merge(arr, low, mid, high); 
	} 
} 

void merge(int* arr, int low, int mid, int high) 
{ 
	int i = low, j = mid + 1, k = 0; 
	int* temp = (int*)calloc(high - low + 1, sizeof(int)); 
	while ((i <= mid) && (j <= high)) 
		if (arr[i] < arr[j]) 
			temp[k++] = arr[i++]; 
		else
			temp[k++] = arr[j++]; 
	while (j <= high) // if( i>mid ) 
		temp[k++] = arr[j++]; 
	while (i <= mid) // j>high 
		temp[k++] = arr[i++]; 

	// copy temp[] to arr[] 
	for (i = low, k = 0; i <= high; i++, k++) 
		arr[i] = temp[k]; 
	free(temp); 
} 

int main() 
{ 
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 }; 
	mergesort(a, 0, 7); 
	for (int i = 0; i < 8; i++) 
		printf("%d ", a[i]); 
	return 0; 
} 
