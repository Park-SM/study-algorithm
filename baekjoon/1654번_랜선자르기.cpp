#include <iostream>
#include <algorithm>
using namespace std;

int cables[10000];

long long makeCable(int n, int k) {
    long long s = 1, e = cables[0], result;
    while (s <= e) {
        long long mid = (s + e) / 2;
        long long count = 0;
        for (int i = 0; i < n; i++) {
            count += cables[i] / mid;
        }
        if (count >= k) {
            if (result < mid) result = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> cables[i];
    sort(cables, cables + n, greater<int>());
    cout << makeCable(n, k);
}
