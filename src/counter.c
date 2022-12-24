#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int counter = 0;
    
    for (int i = 0; i < 1e7; i++) {
        counter = counter + 1;
    }

    printf("done: counter = %d \n", counter);

    return 0;
}