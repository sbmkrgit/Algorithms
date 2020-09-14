// Quick sort in C

#include <stdio.h>

// Function to swap position of elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {

  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    // Select pivot position and put all the elements smaller
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high);

    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);

    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Function to print elements of an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
    int size;
    FILE *file;
    file = fopen("input.txt","r");

    fscanf(file,"%d",&size);

    int arr[size];
    for(int i = 0;i<size;i++)
        fscanf(file,"%d",&arr[i]);

    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array in ascending order: \n");
    printArray(arr, n);
    fclose(file);
    return 0;
}


