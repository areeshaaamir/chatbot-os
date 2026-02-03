include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <string>

using namespace std;

sem_t sem;
int score = 0;

void* quiz(void* arg) {
    string answer;

    sem_wait(&sem);
    cout << "\n\n";
    cout << "\t\tQ1: What does OS stand for?\n";
    getline(cin, answer);
    if (answer == "Operating System" || answer == "operating system")
        score++;
    sem_post(&sem);

    sem_wait(&sem);
    cout << "\n\n";
 cout << "\n\n";
    cout << "\t\tQ2: Which system call creates a new process?\n";
    getline(cin, answer);
    if (answer == "fork")
        score++;
    sem_post(&sem);

    sem_wait(&sem);
    cout << "\n\n";
    cout << "\t\tQ3: Which scheduling uses time quantum?\n";
    getline(cin, answer);
    if (answer == "Round Robin" || answer == "round robin")
        score++;
    sem_post(&sem);

    pthread_exit(NULL);
}

int main() {
    pthread_t t;
    
    sem_init(&sem, 0, 1);

    pthread_create(&t, NULL, quiz, NULL);
    pthread_join(t, NULL);

    sem_destroy(&sem);

    cout << "\nYour final score: " << score << "/3\n";
    return 0;
}
