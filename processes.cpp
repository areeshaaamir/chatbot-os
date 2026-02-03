#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        cout << "Child process executing ls using execvp\n";
        char* args[] = {(char*)"ls", (char*)"-l", NULL};
        execvp(args[0], args);
    } 
    else {
        wait(NULL);
        cout << "Parent process: Child execution completed\n";
    }

    return 0;
}
