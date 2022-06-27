#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int n,m; cin >> n >> m;
    queue<pair<int,int>> q;
    int dist[1000][1000];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dist[i][j]=-1;
    int map[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j]==2){
                q.push({i,j});
                dist[i][j] = 0;
            }
            else if(map[i][j]==0) dist[i][j]=0;
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = dx[dir]+cur.X;
            int ny = dy[dir]+cur.Y;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>=0) continue;
            q.push({nx,ny});
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}