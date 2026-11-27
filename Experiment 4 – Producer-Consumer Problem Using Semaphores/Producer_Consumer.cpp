#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

#define SIZE 5
#define ITEMS 10

int buffer[SIZE];
int in = 0, out = 0;

sem_t emptySlots, fullSlots, mutexSem;

// Producer function
void* producer(void* arg) {
    for (int item = 1; item <= ITEMS; item++) {

        sem_wait(&emptySlots);
        sem_wait(&mutexSem);

        buffer[in] = item;

        cout << "Producer produced: "
             << item << endl;

        in = (in + 1) % SIZE;

        sem_post(&mutexSem);
        sem_post(&fullSlots);

        usleep(100000);
    }

    return nullptr;
}

// Consumer function
void* consumer(void* arg) {
    for (int i = 0; i < ITEMS; i++) {

        sem_wait(&fullSlots);
        sem_wait(&mutexSem);

        int item = buffer[out];

        cout << "Consumer consumed: "
             << item << endl;

        out = (out + 1) % SIZE;

        sem_post(&mutexSem);
        sem_post(&emptySlots);

        usleep(150000);
    }

    return nullptr;
}

int main() {
    pthread_t producerThread, consumerThread;

    // Initialize semaphores
    sem_init(&emptySlots, 0, SIZE);
    sem_init(&fullSlots, 0, 0);
    sem_init(&mutexSem, 0, 1);

    cout << "Producer-Consumer Problem\n";
    cout << "Buffer Size: " << SIZE << endl;
    cout << "Total Items: " << ITEMS << endl;
    cout << endl;

    // Create threads
    pthread_create(&producerThread, nullptr,
                   producer, nullptr);

    pthread_create(&consumerThread, nullptr,
                   consumer, nullptr);

    // Wait for threads to complete
    pthread_join(producerThread, nullptr);
    pthread_join(consumerThread, nullptr);

    // Destroy semaphores
    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);
    sem_destroy(&mutexSem);

    cout << "\nProduction and Consumption Completed."
         << endl;

    return 0;
}


Sample output:

Producer-Consumer Problem
Buffer Size: 5
Total Items: 10

Producer produced: 1
Consumer consumed: 1
Producer produced: 2
Consumer consumed: 2
Producer produced: 3
Consumer consumed: 3
Producer produced: 4
Producer produced: 5
Consumer consumed: 4
Producer produced: 6
Consumer consumed: 5
Producer produced: 7
Producer produced: 8
Consumer consumed: 6
Producer produced: 9
Consumer consumed: 7
Producer produced: 10
Consumer consumed: 8
Consumer consumed: 9
Consumer consumed: 10

Production and Consumption Completed.
