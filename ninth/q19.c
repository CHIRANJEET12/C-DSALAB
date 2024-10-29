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

    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted array :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
