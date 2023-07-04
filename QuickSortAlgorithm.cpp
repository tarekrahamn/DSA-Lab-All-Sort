#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function to rearrange the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choosing the last element as the pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) {\6\
        if (arr[j] < pivot) { // all small element of  pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }
    //next step of pivot\7\
    i++; // pivot akoh last index a ace ar pivot r jonno ek ta hali index lagbe ai jonno i k ek bariya dibo
    swap(arr[i + 1], arr[high]);
    return i ; // pivot index
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partitioning index
        int pivitindex = partition(arr, low, high);

        // Sorting the elements before and after the partition
        quickSort(arr, low, pivitindex - 1); // all small element 
        quickSort(arr, pivitindex + 1, high); // all big element 
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Example usage
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int size = arr.size();

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
