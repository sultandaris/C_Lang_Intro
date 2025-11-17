#include <time.h>
#include <stdio.h>

int main(){
    clock_t start,end,end2,start2;

    start = clock();
    int a = 0;
    a++;
    int i;
    for(i = a;i < 10000000;i++){
        a += 1;
    }
    end = clock();

    double diff = (double) end - start / CLOCKS_PER_SEC;
    printf("%f ", diff);
    
    start2 = clock();
    int b = 0;
    b = b + 1;
    int j;
    for(j = b;j < 10000000;j++){
        b += 1;
    }
    end2 = clock();

    double diff2 = (double) end2 - start2 / CLOCKS_PER_SEC;
    printf("%f", diff2-diff);
    return 0;
}