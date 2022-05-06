#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cnt=0,cnt2=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool vis[100][100]={};
    queue<pair<int,int>> q;
    string board[100]={};
    for(int i=0;i<n;i++) cin >> board[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]) continue;
            else {
                q.push({i,j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.X+dx[dir];
                        int ny = cur.Y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(board[nx][ny]!=board[cur.X][cur.Y]||vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++) fill(vis[i],vis[i]+n,0);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(board[i][j]=='G') board[i][j]='R';

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]) continue;
            else {
                q.push({i,j});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.X+dx[dir];
                        int ny = cur.Y+dy[dir];
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(board[nx][ny]!=board[cur.X][cur.Y]||vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                cnt2++;
            }
        }
    }
    cout << cnt << ' ' << cnt2;
}