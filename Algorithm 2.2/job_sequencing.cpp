#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<string, int>, int> a, pair<pair<string, int>, int> b) {
    return a.first.second > b.first.second;
}

void jobSequencing(vector<pair<pair<string, int>, int>> &jobs, int n) {
    sort(jobs.begin(), jobs.end(), compare);
    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].second);
    }
    
    vector<string> result(maxDeadline, "");
    vector<bool> slotTaken(maxDeadline, false);
    
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        string jobId = jobs[i].first.first;
        int profit = jobs[i].first.second;
        int deadline = jobs[i].second;

        for (int j = min(maxDeadline, deadline) - 1; j >= 0; j--) {
            if (!slotTaken[j]) {
                result[j] = jobId;
                slotTaken[j] = true;
                totalProfit += profit;
                break;
            }
        }
    }

    cout << "Job sequence that maximizes profit: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != "") {
            cout << result[i] << " ";
        }
    }
    cout << endl;

    cout << "Maximum Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<pair<pair<string, int>, int>> jobs(n);

    cout << "Enter the job profits: ";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].first.second;
        jobs[i].first.first = "J" + to_string(i + 1);
    }

    cout << "Enter the job deadlines: ";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].second;
    }

    jobSequencing(jobs, n);

    return 0;
}
