#include <stdio.h>
#include <signal.h>

void handle(int arg) {
    printf("Signal received: %d\n", arg);
}

int main(int argc, char *argv[]) {
    signal(SIGHUP, handle);

    printf("Waiting for some signals..\n");

    // Waiting to handle some signal interrupts
    // Send some signals using: `kill -HUP {PID}`
    while (1)
        ; 

    return 0;
}
