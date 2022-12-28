#include <pthread.h>
#include <stdio.h>

int counter = 0;

void* my_thread_function(void* args) {
  for (int i = 0; i < 1e7; i++) {
    counter = counter + 1;
  }

  return NULL;
}

int main(void) {
  pthread_t thread1;
  pthread_t thread2;

  // Create the first thread
  int rc1 = pthread_create(&thread1, NULL, my_thread_function, NULL);
  
  if (rc1 != 0) {
    // An error occurred
    printf("Error creating thread1\n");
    return 1;
  }

  // Create the second thread
  int rc2 = pthread_create(&thread2, NULL, my_thread_function, NULL);
  
  if (rc2 != 0) {
    // An error occurred
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
