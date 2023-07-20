#include <iostream>
#include <stack>
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
    stack<int> stack;

    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            stack.push(low);
            stack.push(pivotIndex - 1);
        }

        if (pivotIndex + 1 < high) {
            stack.push(pivotIndex + 1);
            stack.push(high);
        }
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
