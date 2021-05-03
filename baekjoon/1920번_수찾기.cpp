#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

int ns[100000];

int search(int s, int e, int t) {
    if (s > e) return 0;
    int mid = ((e - s) / 2) + s;
    if (ns[mid] == t) {
        return 1;
    } else if (ns[mid] < t) {
        return search(mid + 1, e, t);
    }
    return search(s, mid - 1, t);
}

int main() {
    IN_OPT;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> ns[i];
    sort(ns, ns + n);
    
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        cout << search(0, n - 1, t) << "\n";
    }
}
