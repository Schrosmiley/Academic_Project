#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<double, int>, pair<int, int>> a, pair<pair<double, int>, pair<int, int>> b) {
    return a.first.first > b.first.first;  
}

double fractionalKnapsack(int capacity, vector<pair<pair<double, int>, pair<int, int>>>& items, vector<double>& frequency) {
    sort(items.begin(), items.end(), compare);

    double maxProfit = 0;
    
    for (int i = 0; i < items.size(); i++) {
        if (capacity == 0) break;

        int profit = items[i].second.first;
        int weight = items[i].second.second;

        if (weight <= capacity) {
            maxProfit += profit;
            capacity -= weight;
            frequency[items[i].first.second] = 1.0;
        } 
        else {
            maxProfit += profit * ((double)capacity / weight);
            frequency[items[i].first.second] = (double)capacity / weight;
            capacity = 0;
        }
    }
    
    return maxProfit;
}

int main() {
    int n, capacity;
    
    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;
    
    vector<pair<pair<double, int>, pair<int, int>>> items(n);
    vector<double> frequency(n, 0);
    
    cout << "Enter the profit for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].second.first;
    }

    cout << "Enter the weight for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].second.second;
        items[i].first.first = (double)items[i].second.first / items[i].second.second;
        items[i].first.second = i;
    }
    
    double maxProfit = fractionalKnapsack(capacity, items, frequency);
    cout << "Maximum Profit: " << maxProfit << endl;
    
    cout << "\nItems taken:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - " << frequency[i] << "\n";
    }
    
    return 0;
}
