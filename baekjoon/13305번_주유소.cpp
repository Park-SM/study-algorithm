#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

vector<int> loads;
vector<int> cities;

int main() {
    IN_OPT;
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int t; cin >> t;
        loads.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        cities.push_back(t);
    }
    long long result = 0;
    for (int i = 0; i < n - 1;) {
        int j;
        for (j = i + 1; j < n; j++) {
            result += (long long)cities[i] * loads[j - 1];
            if (cities[i] > cities[j] || j == n - 1) break;
        }
        i = j;
    }
    cout << result;
}
