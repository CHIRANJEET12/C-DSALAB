#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Elements with odd index and odd value: \n");
    for (int i = 1; i < n; i += 2) {
        if (ptr[i] % 2 != 0) {
            printf("%d  ", ptr[i]);
        }
    }

    return 0;
}
