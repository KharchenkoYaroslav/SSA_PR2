#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE (1024 * 1024 * 64)  
#define ITERATIONS 100

int array[ARRAY_SIZE];  

double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

void test_cache_overload(int stride) {
    volatile int sum = 0;
    double start_time, end_time;

    start_time = get_time();
    for (int it = 0; it < ITERATIONS; it++) {
        for (int i = 0; i < ARRAY_SIZE; i += stride) {
            sum += array[i];
        }
    }
    end_time = get_time();

    printf("Stride: %4d, Time: %.6f sec\n", stride, end_time - start_time);
}

int main() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }

    printf("Cache overload test:\n");

    for (int stride = 1; stride <= 4096; stride *= 2) {
        test_cache_overload(stride);
    }

    return 0;
}
