#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, j;
    char **arr, temp[100];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", temp);

        arr[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(arr[i], temp); 
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
    printf("\nSorted strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    for (i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

