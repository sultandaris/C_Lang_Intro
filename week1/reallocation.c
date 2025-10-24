#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int** ptr =  malloc(n * sizeof(int*));
    int i,y, count = n;
    for (i = 0; i < count; i++)
    {
        ptr[i] = malloc(3 * sizeof(int));
    }
    //array[n][3]
    for (i = 0; i < count; i++)
    {
        for (y = 0; y < 3; y++)
        {
            ptr[i][y] = y;
        }
    }
    for (i = 0; i < count; i++) {
    for (y = 0; y < 3; y++) {
        printf("%d ", ptr[i][y]);
    }
    printf("\n");
    }

        printf("\n");

    ///    
    int new = 5;
    for(i = 0;i < count;i++){
        ptr[i] = realloc(ptr[i], new * sizeof(int));
    }
    ///

    for (i = 0; i < count; i++)
    {
        for (y = 0; y < new; y++)
        {
            ptr[i][y] = y;
        }
    }

    for (i = 0; i < count; i++) {
    for (y = 0; y < new; y++) {
        printf("%d ", ptr[i][y]);
    }
    printf("\n");
    }

    for (i = 0; i < count; i++) {
        free(ptr[i]);
    }
    free(ptr);
    return 0;
}