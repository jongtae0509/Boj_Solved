#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    int dx[] = {0, 0, 1,-1};
    int dy[] = {1, -1, k,k};
    string board[2];
    queue<pair<pair<int,int>,int>> q;
    bool vis[2][100001] = {};
    for (int i = 0; i < 2; i++) cin >> board[i];
    for (int i = 0; i < 2; i++) for (int j = 0; j < N; j++) vis[i][j] = 0;
    q.push({{0, 0},0});
    vis[0][0] = 1;
    int tm = 0;
    bool check = true;
    while (!q.empty() && check) {
        auto cur = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cur.X.X + dx[d];
            int ny = cur.X.Y + dy[d];
            if (ny >= N) {
                check = false;
                break;
            }
            if (nx < 0 || ny < 0 || nx >= 2||vis[nx][ny]) continue;
            if (board[nx][ny] == '0'||ny<=cur.Y) continue;
            //printf("%d,%d , %d\n",nx,ny,cur.Y);
            q.push({{nx, ny},cur.Y+1});
            vis[nx][ny]=true;
        }
        tm++;

    }
    if (!check) cout << 1;
    else cout << 0;
}
/*
23 5
10000000100010010000000
00011111001111111100100
 */


