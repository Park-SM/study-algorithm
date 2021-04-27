#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 1;;i++) {
        int l, p, v; cin >> l >> p >> v;
        if (l == 0 && p == 0 && v == 0) return 0;
        
        cout << "Case " << i << ": " << ((v / p) * l) + ((v % p > l) ? l : v % p) << "\n";
    }
}
