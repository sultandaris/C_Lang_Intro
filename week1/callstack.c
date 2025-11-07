#include <stdio.h>
#include <stdlib.h>

char* g_gudang_awal = NULL; // Alamat pintu masuk
char* g_gudang_top = NULL;  // Penanda lantai kosong
size_t g_gudang_size = 0;   // Ukuran total

void pop(void* data, size_t size){
    g_gudang_top = g_gudang_top - size;
    char* d = (char *) data;
    size_t i;
    for (i = 0; i < size; i++)
    {
        g_gudang_top[i] = d[i];
    }
} 


void push(void* data, size_t size){
    char* d = (char *) data;
    size_t i;
    for (i = 0; i < size; i++)
    {
        g_gudang_top[i] = d[i];
    }
    g_gudang_top = g_gudang_top + size;
}

int main() {
    int* ptr = malloc(3* sizeof(int));
    g_gudang_size = 3 * sizeof(int);
    g_gudang_awal = (char *) ptr;
    g_gudang_top = (char *) ptr;

    int a = 13;
    int i;
    // push(&a, sizeof(int)); 
    for (i = 0; i < 3; i++)
    {
        printf("%d ", ptr[i]);
    }

    // a = 0;
    // pop(&a,sizeof(int));
    // for (i = 0; i < 2; i++)
    // {
    //     printf("%d ", ptr[i]);
    // }
    
    return 0;
}