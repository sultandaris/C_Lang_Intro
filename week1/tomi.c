#include <stdio.h>

int stringlength(char* source){
    char* val = source;
    while(*source != '\0'){
        source++;
    }
    return source-val;
}

void stringreverse(char* source){
    int val = stringlength(source);
    int i;
    char temp;
    char* end = source + val - 1;
    for (i = 0; i < val/2; i++)
    {
        temp = *source;
        *source++ = *(end);
        *(end)-- = temp;
    }
}

void stringconcatenate(char* source,char* target){
    source += stringlength(source);
    while(*target != '\0'){
        *source = *target;
        source++;
        target++;
    }
    *source = '\0';
}