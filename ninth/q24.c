#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int currSize = 1; currSize < n; currSize *= 2) {
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            int mid = leftStart + currSize - 1;
            int rightEnd = (leftStart + 2 * currSize - 1 < n - 1) ? leftStart + 2 * currSize - 1 : n - 1;

            int n1 = mid - leftStart + 1;
            int n2 = rightEnd - mid;

            int leftArr[n1], rightArr[n2];
            for (int i = 0; i < n1; i++) leftArr[i] = arr[leftStart + i];
            for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];

            int i = 0, j = 0, k = leftStart;

            while (i < n1 && j < n2) {
                if (leftArr[i] <= rightArr[j]) {
                    arr[k++] = leftArr[i++];
                } else {
                    arr[k++] = rightArr[j++];
                }
            }

            while (i < n1) {
                arr[k++] = leftArr[i++];
            }

            while (j < n2) {
                arr[k++] = rightArr[j++];
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
