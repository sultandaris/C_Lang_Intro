#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

// Implementasi 1: Pointer arithmetic (seperti kode kamu)
void stringcopy_pointer(char* source, char* target) {
    while(*source != '\0') {
        *target = *source;
        source++;
        target++;
    }
    *target = '\0';
}

// Implementasi 2: Array indexing
void stringcopy_index(char source[], char target[]) {
    int i = 0;
    while (source[i] != '\0') {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';
}

// Implementasi 3: strcpy bawaan C
void stringcopy_builtin(char* source, char* target) {
    strcpy(target, source);
}

// Fungsi untuk mendapatkan memory usage
size_t get_memory_usage() {
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        return pmc.WorkingSetSize; // dalam bytes
    }
    return 0;
}

// Fungsi benchmark
void benchmark(void (*func)(char*, char*), const char* name, char* source, char* target, int iterations) {
    clock_t start, end;
    double cpu_time_used;
    size_t mem_before, mem_after;
    
    // Reset target untuk setiap test
    memset(target, 0, 1000);
    
    // Ukur memory sebelum
    mem_before = get_memory_usage();
    
    // Ukur waktu
    start = clock();
    for(int i = 0; i < iterations; i++) {
        func(source, target);
    }
    end = clock();
    
    // Ukur memory setelah
    mem_after = get_memory_usage();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\n%s:\n", name);
    printf("  Iterasi: %d kali\n", iterations);
    printf("  Waktu: %.6f detik (%.2f ms)\n", cpu_time_used, cpu_time_used * 1000);
    printf("  Waktu per operasi: %.9f detik\n", cpu_time_used / iterations);
    printf("  Memory sebelum: %zu KB\n", mem_before / 1024);
    printf("  Memory setelah: %zu KB\n", mem_after / 1024);
    printf("  Memory delta: %zd KB\n", (mem_after - mem_before) / 1024);
    printf("  Hasil: '%s'\n", target);
}

int main() {
    const int ITERATIONS = 1000000; // 1 juta iterasi
    
    // Alokasi buffer untuk testing
    char source[1000];
    char target[1000];
    
    // Isi source dengan string panjang
    strcpy(source, "Ini adalah string test yang lumayan panjang untuk benchmark performa!");
    
    printf("=== BENCHMARK STRING COPY ===\n");
    printf("String source: '%s'\n", source);
    printf("Panjang: %zu karakter\n", strlen(source));
    printf("Jumlah iterasi: %d\n", ITERATIONS);
    printf("=============================\n");
    
    // Test 1: Pointer arithmetic
    benchmark(stringcopy_pointer, "Method 1: Pointer Arithmetic", source, target, ITERATIONS);
    
    // Test 2: Array indexing
    benchmark(stringcopy_index, "Method 2: Array Indexing", source, target, ITERATIONS);
    
    // Test 3: strcpy bawaan
    benchmark(stringcopy_builtin, "Method 3: strcpy() Built-in", source, target, ITERATIONS);
    
    printf("\n=============================\n");
    printf("KESIMPULAN:\n");
    printf("- Pointer arithmetic biasanya paling cepat (optimized oleh compiler)\n");
    printf("- Array indexing sedikit lebih lambat (ada kalkulasi offset)\n");
    printf("- strcpy() built-in sudah sangat dioptimasi dan biasanya tercepat\n");
    printf("- Memory usage biasanya sama karena semua pakai stack allocation\n");
    
    return 0;
}
