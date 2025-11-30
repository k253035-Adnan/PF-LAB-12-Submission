#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, newSize, i;
    int *arr;

    printf("Enter initial size of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    newSize = n * 2;
    arr = (int *)realloc(arr, newSize * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed!");
        return 1;
    }

    printf("Enter %d new elements:\n", n);
    for (i = n; i < newSize; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nUpdated array:\n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

