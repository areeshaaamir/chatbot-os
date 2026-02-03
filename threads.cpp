// Guess the number game using threads

include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int secret;

void* generateNumber(void* arg) {
    srand(time(0));
    secret = rand() % 100 + 1;
    pthread_exit(NULL);
}

void* guessNumber(void* arg) {
    int guess;
    while (true) {
        cout << "Guess the number (1-100): ";
        cin >> guess;

        if (guess < secret)
            cout << "Too low!\n";
        else if (guess > secret)
           cout << "Too high!\n";
        else {
            cout << "*** Correct guess! ***\n";
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, generateNumber, NULL);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, guessNumber, NULL);
    pthread_join(t2, NULL);

    return 0;
}
