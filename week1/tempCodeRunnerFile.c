#include <stdio.h>
#include "tomi.h"

void stringconcatenate(char* source,char* target){
    //target jadi source
    source += stringlength(source);
    while(*target != '\0'){
        *source = *target;
        source++;
        target++;
    }
    *source = '\0';
}

int main(){
    char a[100] = "Sultan";
    char b[100] = "Daris";
    stringconcatenate(a,b);
    printf("a:%s",a);
    return 0;
}