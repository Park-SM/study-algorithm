#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> rooms;

bool comparator(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main() {
    int n, s, e;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        rooms.push_back(make_pair(s, e));
    }
    sort(rooms.begin(), rooms.end(), comparator);
    
    int idx = 0, result = 1;
    for (int i = 1; i < rooms.size(); i++) {
        if (rooms[i].first >= rooms[idx].second) {
            result++;
            idx = i;
        }
    }
    cout << result;
}
