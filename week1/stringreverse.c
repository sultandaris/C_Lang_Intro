#include <stdio.h>
#include "tomi.h"

void stringreverse(char* source){
    int val = stringlength(source);
    int i;
    char temp;
    char* end = source + val - 1;
    for (i = 0; i < val/2; i++)
    {
        temp = *source;
        *source = *(end);
        *(end) = temp;
        source++;
        end--;
    }
}

int main(){
    char a[100] = "Sultan";
    stringreverse(a);
    printf("%s\n", a);
    return 0;
}