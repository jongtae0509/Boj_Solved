#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
int main() {
    int r,c; cin >> r >> c;
    string map[100]={};
    int dist[100][100]={};
    queue<pair<int,int>> q;
    for(int i=0;i<100;i++) for(int j=0;j<100;j++) dist[i][j] = -1;
    for(int i=0;i<r;i++) cin >> map[i];
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(map[i][j]=='B') {
                q.push({i, j});
                dist[i][j] = 0;
            }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;
            if(nx<0||ny<0||nx>=r||ny>=c) continue;
            if(dist[nx][ny]>=0||map[nx][ny]=='*') continue;
            if(map[nx][ny]=='C'){
                cout << dist[cur.X][cur.Y]+1;
                return 0;
            }
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }
    }
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            cout << dist[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}