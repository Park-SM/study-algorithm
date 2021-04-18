#include <bits/stdc++.h>
using namespace std;

vector<int> coins;

int main() {
    int total;
    cin >> total;
    total = 1000 - total;
    
    coins.push_back(500);
    coins.push_back(100);
    coins.push_back(50);
    coins.push_back(10);
    coins.push_back(5);
    coins.push_back(1);
    
    int result = 0;
    for (int i = 0; i < coins.size(); i++) {
        result += total / coins[i];
        total %= coins[i];
    }
    cout << result;
}
