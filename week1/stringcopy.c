#include <stdio.h>

void stringcopy(char* source,char* target){
    //target jadi source
    while(*source != '\0'){
        *target = *source;
        source++;
        target++;
    }
    *target = '\0';
}

int main(){
    char a[10] = "Day";
    char b[10] = "Giovanni";
    stringcopy(a,b);
    printf("a:%s b:%s", a , b);
    return 0;
}