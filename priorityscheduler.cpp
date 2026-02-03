include <iostream>
using namespace std;

int main() {
    int n;
    cout << "******PRIORITY SCHEDULER******\n";
    cout << "Lower the number, Higher the priority\n\n";
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], pr[n], wt[n], tat[n];
    for(int i=0;i<n;i++) {
        cout << "Burst Time P" << i+1 << ": ";
        cin >> bt[i];
        cout << "Priority P" << i+1 << ": ";
        cin >> pr[i];
    }

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(pr[i] > pr[j]) {
                swap(pr[i], pr[j]);
                swap(bt[i], bt[j]);
            }
        }
    }

    wt[0] = 0;
    for(int i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    cout << "\nPriority Scheduling:\n";
    cout << "P\tBT\tPR\tWT\tTAT\n";
    for(int i=0;i<n;i++)
        cout << "P" << i+1 << "\t" << bt[i] << "\t" << pr[i] << "\t" << wt[i] << "\t" << tat[i] <<>

    return 0;
}
