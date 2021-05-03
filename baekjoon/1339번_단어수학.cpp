#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

int main() {
    IN_OPT;
    int n; cin >> n;
    int weights[26] = { 0, };
    while(n--) {
        string str; cin >> str;
        for (int i = str.size() - 1, d = 1; i >= 0; i--, d *= 10) {
            weights[str[i] - 'A'] += d;
        }
    }
    sort(weights, weights + 26, greater<int>());
    
    int result = 0;
    for (int i = 0; i < 9; i++) {
        result += weights[i] * (9 - i);
    }
    cout << result;
}
