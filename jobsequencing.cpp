#include <iostream>
#include <algorithm>

using namespace std;

struct Job {
    int id, profit, deadline;
};

// Function to solve the Job Sequencing problem
int jobSequencing(Job jobs[], int n) {
    // Sort the jobs in decreasing order of profit
    sort(jobs, jobs + n, [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });

    int maxProfit = 0, maxDeadline = 0;

    // Find the maximum deadline among all the jobs
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Create an array to keep track of the time slots
    int slots[maxDeadline + 1] = {0};

    // Iterate over all the jobs
    for (int i = 0; i < n; i++) {
        // Find a time slot before the deadline for the current job
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == 0) {
                // Schedule the job in the available time slot
                slots[j] = jobs[i].id;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }

    return maxProfit;
}

int main() {
    int n;

    cout << "Enter the number of jobs: ";
    cin >> n;

    Job jobs[n];

    cout << "Enter the profit and deadline of each job: " << endl;

    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        cin >> jobs[i].profit >> jobs[i].deadline;
    }

    int maxProfit = jobSequencing(jobs, n);

    cout << "The maximum profit that can be obtained is: " << maxProfit << endl;

    return 0;
}
