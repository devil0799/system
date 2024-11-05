#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

// Function to compare items based on value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    for (const auto& item : items) {
        if (W >= item.weight) {
            // If item can be fully taken, add its entire value
            W -= item.weight;
            maxValue += item.value;
        } else {
            // If only a fraction can be taken, add that fraction of its value
            maxValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " - Value: ";
        cin >> items[i].value;
    }

    double maxProfit = fractionalKnapsack(W, items);

    cout << "Maximum value in Knapsack = " << maxProfit << endl;

    return 0;
}
