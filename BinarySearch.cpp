#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow

        if (arr[mid] == target)
            return mid;  // Target found

        if (arr[mid] < target)
            left = mid + 1; // Search in the right half
        else
            right = mid - 1; // Search in the left half
    }
    return -1; // Target not found
}

int main() {
    int n, target;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n]; // Dynamic allocation

    cout << "Enter " << n << " sorted space-separated numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target number: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found in the array." << endl;

    delete[] arr; // Free allocated memory
    return 0;
}
