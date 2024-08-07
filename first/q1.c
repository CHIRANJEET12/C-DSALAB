#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, sum = 0;

    printf("Enter the number of elements to be stored: ");
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

    for (int i = 0; i < n; i++) {
        sum += ptr[i];
    }
    printf("Sum of all elements stored in array is: %d\n", sum);

    printf("Enter the number of spaces to be reallocated: ");
    scanf("%d", &m);

    ptr = realloc(ptr, m * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    printf("Enter the new elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &ptr[i]);
    }

    sum = 0; 
    for (int i = 0; i < m; i++) {
        sum += ptr[i];
    }
    printf("Sum of all elements stored in array after reallocation is: %d\n", sum);


    return 0;
}
