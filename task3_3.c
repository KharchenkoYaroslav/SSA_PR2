#include <stdio.h>

void large_stack_function() {
    int large_array1[10000]; 
    int large_array2[10000]; 

    printf("New stack top: %p\n", &large_array2);
}

int main() {
    int local_var;
    printf("Initial stack top: %p\n", &local_var);

    large_stack_function();

    return 0;
}
