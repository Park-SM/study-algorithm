#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

bool visited[101];
vector<int> edges[101];

void bfs(int s) {
    IN_OPT;
    queue<int> q;
    q.push(s);
    int result = 0;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (visited[p]) continue;
        visited[p] = true;
        result++;
        for (int i = 0; i < edges[p].size(); i++) {
            q.push(edges[p][i]);
        }
    }
    cout << result - 1;
}

int main() {
    int v, e; cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int v1, v2; cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    bfs(1);
}
