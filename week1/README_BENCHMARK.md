# Benchmark String Copy - Perbandingan Performa

## Hasil Benchmark

Dari hasil test dengan **1 juta iterasi** pada string 69 karakter:

| Method | Waktu Total | Waktu/Operasi | Memory Delta |
|--------|-------------|---------------|--------------|
| Pointer Arithmetic | 123 ms | 0.123 μs | 0 KB |
| Array Indexing | 102 ms | 0.102 μs | 0 KB |
| **strcpy() Built-in** | **10 ms** | **0.010 μs** | **4 KB** |

## Kesimpulan

### 🏆 Kecepatan:
1. **strcpy()** - **TERCEPAT** (12x lebih cepat!)
   - Sudah dioptimasi compiler dengan assembly khusus
   - Mungkin pakai SIMD instructions untuk copy bulk data
   
2. **Array Indexing** - Cukup cepat
   - Compiler bisa optimize dengan baik
   - Overhead minimal dari array bounds calculation
   
3. **Pointer Arithmetic** - Agak lebih lambat
   - Lebih banyak operasi increment pointer
   - Tapi masih sangat efisien

### 💾 Memory:
- Semua method pakai memory yang **sama** (~3.3 MB)
- Tidak ada memory leak
- Stack allocation jadi sangat efisien

## Cara Pakai

### Compile:
```powershell
gcc -std=c99 benchmark.c -o benchmark.exe -lpsapi
```

### Run:
```powershell
.\benchmark.exe
```

## Penjelasan Teknis

### 1. Mengukur Waktu
```c
clock_t start = clock();
// ... kode yang diukur ...
clock_t end = clock();
double waktu = (double)(end - start) / CLOCKS_PER_SEC;
```

### 2. Mengukur Memory
```c
PROCESS_MEMORY_COUNTERS pmc;
GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
size_t memory = pmc.WorkingSetSize; // dalam bytes
```

### 3. Kenapa strcpy() Lebih Cepat?

strcpy() dari C standard library:
- Ditulis dalam assembly yang highly optimized
- Pakai SIMD (Single Instruction Multiple Data) kalau tersedia
- Bisa copy beberapa bytes sekaligus, bukan satu-satu
- Sudah di-test dan optimize bertahun-tahun

## Tips Optimasi

1. **Untuk production code**: Pakai `strcpy()` atau `strncpy()` (lebih aman)
2. **Untuk learning**: Pointer arithmetic bagus untuk pahami cara kerja memory
3. **Untuk safety**: Selalu cek buffer size dengan `strncpy()` atau `strcpy_s()`

## Compile Flags

- `-std=c99`: Pakai C99 standard (support variable declaration di loop)
- `-lpsapi`: Link dengan Process Status API library (untuk memory tracking)
- `-O3`: (optional) Maximum optimization untuk performa lebih baik

## Contoh dengan Optimization

Coba compile dengan optimization level 3:
```powershell
gcc -std=c99 -O3 benchmark.c -o benchmark_optimized.exe -lpsapi
.\benchmark_optimized.exe
```

Hasilnya akan jauh lebih cepat karena compiler melakukan:
- Loop unrolling
- Inline function calls
- Register allocation optimization
- Dead code elimination
