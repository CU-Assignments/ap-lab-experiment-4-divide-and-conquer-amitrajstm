#include <iostream>

using namespace std;

// Partition function (Lomuto's Partition Scheme)
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // Choose last element as pivot
    int i = left; // Pointer for smaller element

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]); // Place pivot at correct position
    return i; // Return pivot index
}

// QuickSort function
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);  // Sort left part
        quickSort(arr, pivotIndex + 1, right); // Sort right part
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n]; // FIX: Dynamic allocation instead of VLAs
    cout << "Enter " << n << " space-separated numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Apply QuickSort
    quickSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr; // FIX: Free dynamically allocated memory

    return 0;
}
