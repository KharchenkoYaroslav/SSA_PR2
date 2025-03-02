#include <stdio.h>
#include <stdlib.h>

int global_var;             
int initialized_var = 30;   

void function() {}         

int main() {
    int local_var;            
    int *heap_var = malloc(sizeof(int)); 

    printf("Text segment (function address): %p\n", (void*)function);
    printf("Initialized data segment: %p\n", (void*)&initialized_var);
    printf("BSS segment: %p\n", (void*)&global_var);
    printf("Heap segment: %p\n", (void*)heap_var);
    printf("Stack segment: %p\n", (void*)&local_var);

    free(heap_var);
    return 0;
}
