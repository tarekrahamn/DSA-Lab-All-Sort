#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) { // Find Max element in array
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int count[max + 1];
    int sortedArr[n];
    for (int i = 0; i <= max; i++) { // The count Array is  blank
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;// counting the aray element
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];  // add all element eacother withot first element
    }
    for (int i = n - 1; i >= 0; i--) {
        sortedArr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sortedArr[i]);
    }

    return 0;
}
