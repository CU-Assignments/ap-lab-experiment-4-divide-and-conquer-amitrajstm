#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int* temp = new int[right - left + 1]; 

    while (i <= mid && j <= right)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];

    delete[] temp; 
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n]; 

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    delete[] arr; 
}
