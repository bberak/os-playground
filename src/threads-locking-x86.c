#include <pthread.h>
#include <stdio.h>

typedef struct __lock_t {
    int flag;
} lock_t;

int counter = 0;
lock_t counter_lock;

int compare_and_swap(volatile int *ptr, int old, int new) {
    __asm__ __volatile__ (
        "lock\n"
        "cmpxchgl %1,%2\n" 
        : "=a" (old) 
        : "q" (new), "m" (*ptr), "0" (old) 
        : "memory"
    );

    return old;
}

void init(lock_t *lock) {
    // 0 indicates that lock is available, 1 inidicates that lock is held
    lock->flag = 0;
}

void lock(lock_t *lock) {
    while (compare_and_swap(&lock->flag, 0, 1) == 1)
        ; // Do nothing (spin-wait)
}

void unlock(lock_t *lock) {
    lock->flag = 0;
}

void* start_counting(void* args) {
    // Acquire the lock
    lock(&counter_lock);

    for (int i = 0; i < 1e7; i++) {
        counter = counter + 1;
    }

    // Release the lock
    unlock(&counter_lock);

    return NULL;
}

int main(void) {
    // Initialise the lock
    init(&counter_lock);

    pthread_t thread1;
    pthread_t thread2;
    
    // Create the first thread
    if (pthread_create(&thread1, NULL, start_counting, NULL) != 0) {
        printf("Error creating thread1\n");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, start_counting, NULL) != 0) {
        printf("Error creating thread2\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print result of counting
    printf("counter: %d\n", counter);

    return 0;
}
