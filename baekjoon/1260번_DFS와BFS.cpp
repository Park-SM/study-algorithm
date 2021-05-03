#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

bool visited[1001];
vector<int> edges[1001];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < edges[s].size(); i++) {
        dfs(edges[s][i]);
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (visited[p]) continue;
        visited[p] = true;
        cout << p << " ";
        for (int i = 0; i < edges[p].size(); i++) {
            q.push(edges[p][i]);
        }
    }
}

int main() {
    IN_OPT;
    int v, e, s;
    cin >> v >> e >> s;
    for (int i = 0; i < e; i++) {
        int v1, v2; cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    for (int i = 0; i < v; i++) {
        sort(edges[i].begin(), edges[i].end());
    }
    
    dfs(s); cout << "\n";
    fill_n(visited, 1001, false);
    bfs(s);
}
