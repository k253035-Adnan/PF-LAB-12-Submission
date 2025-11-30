#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, extra, i;
    float *sales;
    float total = 0;

    printf("Enter number of days: ");
    scanf("%d", &n);

    sales = (float *)malloc(n * sizeof(float));
    if (sales == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter sales for each day:\n");
    for (i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &sales[i]);
        total += sales[i];
    }
    printf("\nTotal sales for %d days = %.2f\n", n, total);

    printf("\nEnter number of extra days to add: ");
    scanf("%d", &extra);
    sales = (float *)realloc(sales, (n + extra) * sizeof(float));
    if (sales == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    
    printf("\nEnter sales for the extra days:\n");
    for (i = n; i < n + extra; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &sales[i]);
        total += sales[i];
    }

    printf("\nUpdated total sales for %d days = %.2f\n", n + extra, total);

    free(sales);
    return 0;
}

