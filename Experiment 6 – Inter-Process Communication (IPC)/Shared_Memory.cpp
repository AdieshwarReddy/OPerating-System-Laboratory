#include <iostream>
#include <cstring>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main() {
    // Create shared memory
    int shmid = shmget(IPC_PRIVATE, 1024, 0666);

    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach shared memory
    char* data = (char*)shmat(shmid, nullptr, 0);

    if (data == (char*)-1) {
        perror("shmat");
        shmctl(shmid, IPC_RMID, nullptr);
        return 1;
    }

    // Parent writes data
    strcpy(data, "Hello from Parent Process!");

    cout << "Shared Memory Communication\n";

    cout << "Parent writes: "
         << data << endl;

    // Create child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        shmdt(data);
        shmctl(shmid, IPC_RMID, nullptr);
        return 1;
    }

    if (pid == 0) {
        // Child reads shared memory
        cout << "Child reads: "
             << data << endl;

        shmdt(data);
        return 0;
    }

    // Wait for child process
    wait(nullptr);

    // Detach shared memory
    shmdt(data);

    // Remove shared memory
    shmctl(shmid, IPC_RMID, nullptr);

    cout << "Shared memory removed successfully."
         << endl;

    return 0;
}


Sample output:
Shared Memory Communication
Parent writes: Hello from Parent Process!
Child reads: Hello from Parent Process!
Shared memory removed successfully.
  
