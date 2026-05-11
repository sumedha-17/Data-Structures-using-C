#include <stdio.h> 
void printArray(int arr[], int n) { 
for (int i = 0; i < n; i++) { 
printf("%d ", arr[i]); 
} 
printf("\n"); 
} 
int partition(int arr[], int low, int high) { 
int pivot = arr[low]; 
int l = low + 1; 
int r = high; 
int temp; 
while (l <= r) { 
while (l <= r && arr[l] <= pivot) { 
l++; 
} 
while (l <= r && arr[r] > pivot) { 
r--; 
} 
if (l < r) { 
temp = arr[l]; 
arr[l] = arr[r]; 
arr[r] = temp; 
} 
} 
// Place pivot in its correct position 
temp = arr[low]; 
arr[low] = arr[r]; 
arr[r] = temp; 
return r; // pivot index 
} 
void quickSort(int arr[], int low, int high, int n) { 
if (low < high) { 
int pi = partition(arr, low, high); 
printf("After partition around pivot %d (index %d): ", arr[pi], pi); 
printArray(arr, n); 
quickSort(arr, low, pi - 1, n); 
quickSort(arr, pi + 1, high, n); 
} 
} 
int main() { 
int n = 9; 
int arr[9]; 
printf("Enter 9 elements:\n"); 
for (int i = 0; i < n; i++) { 
scanf("%d", &arr[i]); 
} 
quickSort(arr, 0, n - 1, n); 
printf("\nSorted array:\n"); 
printArray(arr, n); 
return 0; 
} 
