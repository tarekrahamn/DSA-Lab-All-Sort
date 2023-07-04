#include<bits/stdc++.h>
using namespace std;
void selectionSort() {
    int  n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    selectionSort();
}
/*
Note:
Worst case is O(n^2) 
Best case is O(n^2)
*/