#include <bits/stdc++.h>

using namespace std;

int estimates[25][25];
int mx[4] = { 0, 1, 0, -1 };
int my[4] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> board) {
    
    fill(&estimates[0][0], &estimates[24][25], INT_MAX);
    
    queue<vector<int>> q;       // vector<int> == [x, y, direction, straightRoad, corner]
    q.push({1, 0, 1, 1, 0});
    q.push({0, 1, 2, 1, 0});
    estimates[0][0] = 0;
    
    int n = board.size();
    while (!q.empty()) {
        vector<int> p = q.front(); q.pop();
            
        int tmpEstimate = (p[3] * 100) + (p[4] * 500);
        if (board[p[1]][p[0]] || estimates[p[1]][p[0]] < tmpEstimate) continue;
        estimates[p[1]][p[0]] = tmpEstimate;
        
        for (int d = 0; d < 4; d++) {
            int x = p[0] + mx[d];
            int y = p[1] + my[d];
            
            if (y < 0 || x >= n || y >= n || x < 0) continue;
            q.push({x, y, d, p[3] + 1, (p[2] % 2 == d % 2) ? p[4] : p[4] + 1});
        }
    }
    
    return estimates[n - 1][n - 1];
}
