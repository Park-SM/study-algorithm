#include <bits/stdc++.h>
using namespace std;

int graph[25][25];
vector<int> ans;

int dfs(int n, int x, int y) {
    if (graph[y][x] != 1) return 0;
    graph[y][x] = 2;
    
    int result = 1;
    if (y - 1 >= 0) result += dfs(n, x, y - 1);
    if (x + 1 < n) result += dfs(n, x + 1, y);
    if (y + 1 < n) result += dfs(n, x, y + 1);
    if (x - 1 >= 0) result += dfs(n, x - 1, y);
    return result;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", graph[i] + j);
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int result = dfs(n, x, y);
            if (result != 0) {
                ans.push_back(result);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}
