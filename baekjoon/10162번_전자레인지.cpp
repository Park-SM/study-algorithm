#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

int times[3] = { 300, 60, 10 };
int click[3] = { 0, };

int main() {
    IN_OPT;
    int t; cin >> t;
    if (t % 10 != 0) {
        cout << -1;
    } else {
        for (int i = 0; i < 3; i++) {
            click[i] = t / times[i];
            t %= times[i];
        }
        cout << click[0] << " " << click[1] << " " << click[2];
    }
}
