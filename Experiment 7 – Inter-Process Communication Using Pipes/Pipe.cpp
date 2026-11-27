#include <iostream>
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int fd[2];
    char buffer[100] = {};

    const char* message =
        "Hello from Parent Process!";

    // Create pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    cout << "IPC Using Pipes" << endl;

    // Create child process
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        return 1;
    }

    if (pid > 0) {

        // Parent process
        // Close unused read end
        close(fd[0]);

        cout << "Parent sends: "
             << message << endl;

        // Write message into pipe
        if (write(fd[1], message,
                  strlen(message)) == -1) {
            perror("write");
            close(fd[1]);
            wait(nullptr);
            return 1;
        }

        // Close write end
        close(fd[1]);

        // Wait for child process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) &&
            WEXITSTATUS(status) == 0) {
            cout << "Communication completed successfully."
                 << endl;
        } else {
            cout << "Communication failed." << endl;
            return 1;
        }

    } else {

        // Child process
        // Close unused write end
        close(fd[1]);

        // Read message from pipe
        ssize_t bytes = read(fd[0], buffer,
                             sizeof(buffer) - 1);

        if (bytes <= 0) {
            cerr << "Failed to receive message." << endl;
            close(fd[0]);
            return 1;
        }

        buffer[bytes] = '\0';

        cout << "Child receives: "
             << buffer << endl;

        // Close read end
        close(fd[0]);
    }

    return 0;
}


Sample output:

IPC Using Pipes
Parent sends: Hello from Parent Process!
Child receives: Hello from Parent Process!
Communication completed successfully.
