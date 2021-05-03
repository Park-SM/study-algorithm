#include <bits/stdc++.h>
using namespace std;

int graph[100][100];

void solution(int n, int m) {
    int x = 0, y = 0, count;
    queue<pair<int, int>> q;
    q.push({x, y});
    graph[y][x] = 2;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        x = p.first, y = p.second;
        count = graph[y][x] + 1;
        if (y - 1 >= 0 && graph[y - 1][x] == 1) {
            graph[y - 1][x] = count;
            q.push({x, y - 1});
        }
        if (x + 1 < m && graph[y][x + 1] == 1) {
            graph[y][x + 1] = count;
            q.push({x + 1, y});
        }
        if (y + 1 < n && graph[y + 1][x] == 1) {
            graph[y + 1][x] = count;
            q.push({x, y + 1});
        }
        if (x - 1 >= 0 && graph[y][x - 1] == 1) {
            graph[y][x - 1] = count;
            q.push({x - 1, y});
        }
    }
    cout << graph[n - 1][m - 1] - 1;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", graph[i] + j);
        }
    }
    solution(n, m);
}
