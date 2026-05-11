#include <stdio.h> 
void printArray(int arr[], int n) { 
for (int i = 0; i < n; i++) { 
printf("%d ", arr[i]); 
} 
printf("\n"); 
} 
void merge(int arr[], int left, int mid, int right, int n) { 
int n1 = mid - left + 1; 
int n2 = right - mid; 
int L[n1], R[n2]; 
for (int i = 0; i < n1; i++) 
L[i] = arr[left + i]; 
for (int j = 0; j < n2; j++) 
R[j] = arr[mid + 1 + j]; 
int i = 0, j = 0, k = left; 
while (i < n1 && j < n2) { 
if (L[i] <= R[j]) { 
arr[k++] = L[i++]; 
} else { 
arr[k++] = R[j++]; 
} 
} 
while (i < n1) { 
arr[k++] = L[i++]; 
} 
while (j < n2) { 
arr[k++] = R[j++]; 
} 
printf("After merging (%d to %d): ", left, right); 
printArray(arr, n); 
} 
void mergeSort(int arr[], int left, int right, int n) { 
if (left < right) { 
int mid = left + (right - left) / 2; 
mergeSort(arr, left, mid, n); 
mergeSort(arr, mid + 1, right, n); 
merge(arr, left, mid, right, n); 
} 
} 
int main() { 
int n = 9; 
int arr[9]; 
printf("Enter 9 elements:\n"); 
for (int i = 0; i < n; i++) { 
scanf("%d", &arr[i]); 
} 
printf("\n=== Merge Sort Process ===\n"); 
mergeSort(arr, 0, n - 1, n); 
printf("\nSorted array:\n"); 
printArray(arr, n); 
return 0; 
} 
