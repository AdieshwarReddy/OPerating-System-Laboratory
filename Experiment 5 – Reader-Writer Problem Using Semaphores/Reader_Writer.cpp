#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t mutexSem, writeSem;

int readerCount = 0;
int sharedData = 0;

// Reader function
void* reader(void* arg) {
    int id = *(int*)arg;

    sem_wait(&mutexSem);

    readerCount++;

    if (readerCount == 1)
        sem_wait(&writeSem);

    sem_post(&mutexSem);

    // Reading shared data
    sem_wait(&mutexSem);

    cout << "Reader " << id
         << " reads data: "
         << sharedData << endl;

    sem_post(&mutexSem);

    usleep(100000);

    sem_wait(&mutexSem);

    readerCount--;

    if (readerCount == 0)
        sem_post(&writeSem);

    sem_post(&mutexSem);

    return nullptr;
}

// Writer function
void* writer(void* arg) {
    int id = *(int*)arg;

    sem_wait(&writeSem);

    // Writing shared data
    sharedData += 10;

    cout << "Writer " << id
         << " writes data: "
         << sharedData << endl;

    usleep(100000);

    sem_post(&writeSem);

    return nullptr;
}

int main() {
    pthread_t readers[3], writers[2];

    int readerID[3] = {1, 2, 3};
    int writerID[2] = {1, 2};

    // Initialize semaphores
    sem_init(&mutexSem, 0, 1);
    sem_init(&writeSem, 0, 1);

    cout << "Reader-Writer Problem\n";
    cout << "Initial Shared Data: "
         << sharedData << endl;

    cout << "Number of Readers: 3\n";
    cout << "Number of Writers: 2\n\n";

    // Create reader threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&readers[i], nullptr,
                       reader, &readerID[i]);
    }

    // Create writer threads
    for (int i = 0; i < 2; i++) {
        pthread_create(&writers[i], nullptr,
                       writer, &writerID[i]);
    }

    // Wait for reader threads
    for (int i = 0; i < 3; i++)
        pthread_join(readers[i], nullptr);

    // Wait for writer threads
    for (int i = 0; i < 2; i++)
        pthread_join(writers[i], nullptr);

    // Destroy semaphores
    sem_destroy(&mutexSem);
    sem_destroy(&writeSem);

    cout << "\nFinal Shared Data: "
         << sharedData << endl;

    cout << "Reader-Writer Execution Completed."
         << endl;

    return 0;
}


Sample output:

Reader-Writer Problem
Initial Shared Data: 0
Number of Readers: 3
Number of Writers: 2

Reader 1 reads data: 0
Reader 2 reads data: 0
Reader 3 reads data: 0
Writer 1 writes data: 10
Writer 2 writes data: 20

Final Shared Data: 20
Reader-Writer Execution Completed.
