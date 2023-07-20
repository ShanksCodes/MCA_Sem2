#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function to place the pivot at its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int leftPtr = low + 1;
    int rightPtr = high;

    while (true) {
        // Move the left pointer to find the element greater than the pivot
        while (leftPtr <= rightPtr && arr[leftPtr] <= pivot) {
            leftPtr++;
        }

        // Move the right pointer to find the element smaller than the pivot
        while (leftPtr <= rightPtr && arr[rightPtr] > pivot) {
            rightPtr--;
        }

        // If the pointers cross each other, break the loop
        if (leftPtr > rightPtr) {
            break;
        }

        // Swap the elements at the left and right pointers
        swap(arr[leftPtr], arr[rightPtr]);
    }

    // Move the pivot to its correct position
    swap(arr[low], arr[rightPtr]);
    return rightPtr;
}

// Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
