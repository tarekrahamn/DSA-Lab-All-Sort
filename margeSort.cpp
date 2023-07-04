#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// recursion r problem gula dfs r kaj kore 
// Merge two sorted subarrays into a single sorted subarray
void merge(vector<int>& arr, int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    // Create temporary arrays
    vector<int> L(n1), R(n2); 
    // Copy data to temporary arrays L[]    and R[]
    for (i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[middle + 1 + j];
    }

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function and give me final sort array
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle =  (right +left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

// Function to print the elements of an array
void printArray(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    //int size = arr.size();
    cout << "Original array: ";
    printArray(arr);
    mergeSort(arr, 0, n   -1);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
/*
Time compelexity : 
divide and conqure so logn
and sort for n
total time :nlogn


Recursive call time:
T(n)=(T(n/2)+T(n/2))+O(n)       [       (O(n)Sorting time)   }
    =2T(n/2)+O(n)
    =




Master theory:
  T(n) = T(n/b)+F(n)    

*/
