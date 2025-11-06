#include <stdio.h>
#include <stdlib.h>

int memorycompare(void* s1, void* s2, size_t n){
    char* x = (void *) s1;
    char* y = (void *) s2;
    size_t i = 0;
    for (i = 0; i < n; i++)
    {
        if(x[i] > y[i]){
            return 1;
        } else if (x[i] < y[i])
        {
            return -1;
        }
    }
    return 0;
}

int main(){
    int a[] = {0,0,0,0};
    int b[] = {0,0,0,0};
    int hasil = memorycompare(a,b,4 * sizeof(int));
    printf("%d",hasil);
    return 0;
}