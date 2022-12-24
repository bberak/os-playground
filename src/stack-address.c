// References: https://cs2461-2020.github.io/lectures/runtimestack.pdf
// See slides 10 and 11 for an example of a symbol table that is used
// by a C compiler to track the address offsets of variables on the stack.
// Therefore to print the address of a variable - the compiler could look up a
// variable in the symbol table and apply the offset to the stack pointer to
// get the address..

#include <stdio.h>

int main(int argc, char *argv[]) {
    int var1 = 0;
    int var2 = 0;
    int var3 = 0;
    int var4 = 0; 

    printf("var1 address: %p\n", &var1);
    printf("var2 address: %p\n", &var2);
    printf("var3 address: %p\n", &var3);
    printf("var4 address: %p\n", &var4);

    var1 = var1 + 1; 
    var2 = var2 + 1;
    var3 = var3 + 1;
    var4 = var4 + 1;

    printf("var1 address: %p\n", &var1);
    printf("var2 address: %p\n", &var2);
    printf("var3 address: %p\n", &var3);
    printf("var4 address: %p\n", &var4);

    int var5 = var1;
    int var6 = var2;
    int var7 = var3;
    int var8 = var4;

    printf("var5 address: %p\n", &var5);
    printf("var6 address: %p\n", &var6);
    printf("var7 address: %p\n", &var7);
    printf("var8 address: %p\n", &var8);

    return 0;
}