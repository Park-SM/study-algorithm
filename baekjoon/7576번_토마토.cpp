#include <bits/stdc++.h>
#define IN_OPT std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr)
using namespace std;

typedef struct _tagTomato {
    int x;
    int y;
    int day;
} Tomato;
bool visited[1001][1001];
int graph[1001][1001];
queue<Tomato> q;

bool isVisitedAll(int mx, int my) {
    for (int y = 0; y < my; y++) {
        for (int x = 0; x < mx; x++) {
            if (!visited[y][x]) return false;
        }
    }
    return true;
}

int bfs(int mx, int my) {
    int result;
    while (!q.empty()) {
        Tomato p = q.front(); q.pop();
        if (visited[p.y][p.x]) continue;
        visited[p.y][p.x] = true;
        result = p.day;
        if (p.y > 0 && graph[p.y - 1][p.x] == 0 && !visited[p.y - 1][p.x]) {
            q.push({p.x, p.y - 1, p.day + 1});
        }
        if (p.x + 1 < mx && graph[p.y][p.x + 1] == 0 && !visited[p.y][p.x + 1]) {
            q.push({p.x + 1, p.y, p.day + 1});
        }
        if (p.y + 1 < my && graph[p.y + 1][p.x] == 0 && !visited[p.y + 1][p.x]) {
            q.push({p.x, p.y + 1, p.day + 1});
        }
        if (p.x > 0 && graph[p.y][p.x - 1] == 0 && !visited[p.y][p.x - 1]) {
            q.push({p.x - 1, p.y, p.day + 1});
        }
    }
    return (isVisitedAll(mx, my) ? result : -1);
}

int main() {
    IN_OPT;
    int m, n; cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                q.push({j, i, 0});
            } else if (graph[i][j] == -1) {
                visited[i][j] = true;
            }
        }
    }
    cout << bfs(m, n);
}
