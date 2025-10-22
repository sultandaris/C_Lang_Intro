#include <stdio.h>

int stringlength(char* source){
    char* val = source;
    while(*source != '\0'){
        source++;
    }
    return source-val;
}

int main(){
    char a[] = "daris";
    printf("length: %d", stringlength(a));
}