#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 2; i <= n; i++) {
        key = arr[i];
        j = i - 1;

        while (j > 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            //printf("%d\n",j);
        }
        arr[j + 1] = key;
        //printf("%d\n",i);// i=2 , 3 . 4 ,5
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array: ");
    for (int i = 1; i <=n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
