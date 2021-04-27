#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

map<pair<int, int>, char> graph;

int bfs(int m, int n, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    int result = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        if (graph.count({p.first, p.second}) == 0) continue;
        graph.erase({p.first, p.second});
        result++;
        if (p.second - 1 >= 0 && graph.count({p.first, p.second - 1}) != 0) q.push({p.first, p.second - 1});
        if (p.first + 1 < m && graph.count({p.first + 1, p.second}) != 0) q.push({p.first + 1, p.second});
        if (p.second + 1 < n && graph.count({p.first, p.second + 1}) != 0) q.push({p.first, p.second + 1});
        if (p.first - 1 >= 0 && graph.count({p.first - 1, p.second}) != 0) q.push({p.first - 1, p.second});
    }
    return result;
}

int main() {
    IN_OPT;
    int t; cin >> t;
    while(t--) {
        int m, n, k; cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            int v1, v2; cin >> v1 >> v2;
            graph[{v1, v2}] = ' ';
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (bfs(m, n, j, i) != 0) result++;
            }
        }
        cout << result << "\n";
        for (int i = 0; i < k; i++) graph.clear();
    }
}
