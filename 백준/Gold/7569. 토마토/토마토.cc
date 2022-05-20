#include <bits/stdc++.h>

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int board[103][103][103];
int dist[103][103][103];
queue<tuple<int, int, int>> Q;

int main() {
    int m, n, h;
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int t; cin >> t;
                board[j][k][i] = t;
                if (t == 1) Q.push({j, k, i});
                if (t == 0) dist[j][k][i] = -1;
            }
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        for (int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nx][ny][nz] >= 0) continue;
            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            Q.push({nx, ny, nz});
        }
    }
    int a = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[j][k][i] == -1) {
                    cout << -1;
                    return 0;
                }
                a = max(a, dist[j][k][i]);
            }
        }
    }
    cout << a;
}