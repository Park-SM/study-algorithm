#include <bits/stdc++.h>
using namespace std;

vector<int> coins;

int main() {
    int n, k, input;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> input;
        coins.push_back(input);
    }
    sort(coins.begin(), coins.end(), greater<int>());
    
    int result = 0;
    for (int i = 0; i < coins.size(); i++) {
        result += k / coins[i];
        k %= coins[i];
    }
    cout << result;
}
