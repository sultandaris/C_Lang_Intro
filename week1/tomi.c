#include <stdio.h>

int stringlength(char* source){
    char* val = source;
    while(*source != '\0'){
        source++;
    }
    return source-val;
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