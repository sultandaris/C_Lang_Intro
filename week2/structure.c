#include <stdio.h>
#include <string.h>

typedef struct kucing
{
    char nama[20];
    int umur;
}meong;

int main(){
    meong vigo;
    strcpy(vigo.nama,"Vigo");
    vigo.umur = 2;
    printf("%s \n",vigo.nama);
    printf("%d tahun",vigo.umur);
    return 0;
}
