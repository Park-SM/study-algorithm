#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

int cards[500000];

int main() {
    IN_OPT;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> cards[i];
    sort(cards, cards + n);
    
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        cout << upper_bound(cards, cards + n, t) - lower_bound(cards, cards + n, t) << " ";
    }
}
