#include <bits/stdc++.h>
using namespace std;

vector<int> ropes;

int main() {
    int n, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r;
        ropes.push_back(r);
    }
    sort(ropes.begin(), ropes.end());
    
    int maxWeight = 0;
    for (int i = 0; i < n; i++) {
        maxWeight = max(maxWeight, ropes[i] * (n - i));
    }
    cout << maxWeight;
}
