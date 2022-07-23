#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
int main() {
    int n,m; cin >> m >> n;
    bool map[250][250]={};
    bool vis[250][250]={};
    int cnt = 0;
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin >> map[i][j];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==1&&!vis[i][j]){
                cnt++;
                vis[i][j]=1;
                q.push({i,j});
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 8; dir++) {
                        int nx = dx[dir] + cur.X;
                        int ny = dy[dir] + cur.Y;
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        if (map[cur.X][cur.Y] != map[nx][ny]) continue;
                        if (vis[nx][ny]) continue;
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    cout << cnt;

}