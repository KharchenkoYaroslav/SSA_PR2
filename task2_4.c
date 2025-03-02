#include <stdio.h>

void test_function() {
    int local_array1[1000];         
    int local_array2[1000] = {1};   
    printf("Inside function\n");
}

int main() {
    test_function();
    printf("Hello, World!\n");
    return 0;
}
