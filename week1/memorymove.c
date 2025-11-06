#include <stdio.h>
#include <stdlib.h>

void memorymove(void* target, void* source, size_t n){
    char* t = (void *) target;
    char* s = (void *) source;
    size_t i = 0;
    if (target > source)
    {
        for (i = n; i > 0; i--){
            t[i-1] = s[i-1];
        }
    } else if (target < source)
    {
        for (i = 0; i < n; i++){
            t[i] = s[i];
        }
    }
}

int main(){
    int a[] = {1,2,3,4};
    int b[] = {0,0,0,0};
    memorymove(b+1,a,3 * sizeof(int));
    int i=0;
    for ( i = 0; i < 4; i++)
    {
        printf("%d",b[i]);
    }
    
    return 0;
}