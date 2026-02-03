#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("chatlog.txt");
    string line;

    if (!file) {
        cout << "No chat history found.\n";
        return 0;
    }

    cout << "**** Chat History: ****\n";
    cout << "------------------\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}

