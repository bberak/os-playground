#include <pthread.h>
#include <stdio.h>

volatile int counter = 0;
pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;

void* start_counting(void* args) {
    // Obtain lock before counting (critical section)
    pthread_mutex_lock(&counter_lock);

    for (int i = 0; i < 1e7; i++) {
        counter = counter + 1;    
    }

    // Release lock when complete
    pthread_mutex_unlock(&counter_lock);

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_t thread2;
    
    // Create the first thread
    if (pthread_create(&thread1, NULL, start_counting, NULL) != 0) {
        printf("Error creating thread1\n");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread1, NULL, start_counting, NULL) != 0) {
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
