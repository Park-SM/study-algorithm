#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m, t;
    cin >> h >> m;
    h = (h == 0) ? 24 : h;
    t = (h * 60) + m - 45;
    cout << ((t / 60 == 24) ? 0 : t / 60) << ' ' << t % 60;
}
