#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int n,m; cin >> n >> m;
    pair<int,int> h,e;
    queue<pair<pair<int,int>,int>> q;
    cin >> h.X >> h.Y;
    cin >> e.X >> e.Y;
    bool mp[1000][1000]={};
    int dist[1000][1000][2]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mp[i][j];
            dist[i][j][0]=dist[i][j][1]=-1;
        }
    }
    q.push({{h.X-1,h.Y-1},0});
    dist[h.X-1][h.Y-1][0] = 0;
    bool check = false;
    while(!q.empty()){
        auto cur=q.front(); q.pop();
        if(cur.X.X==e.X-1&&cur.X.Y==e.Y-1){
            cout << dist[cur.X.X][cur.X.Y][cur.Y];
            check = true;
            break;
        }
        for(int dir=0;dir<4;dir++){
            int nx = cur.X.X+dx[dir];
            int ny = cur.X.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(mp[nx][ny]&&!cur.Y&&dist[nx][ny][cur.Y+1]<0){
                dist[nx][ny][cur.Y+1] = dist[cur.X.X][cur.X.Y][cur.Y] + 1;
                q.push({{nx,ny},cur.Y+1});
            }
            else if(!mp[nx][ny]&&dist[nx][ny][cur.Y]<0){
                dist[nx][ny][cur.Y] = dist[cur.X.X][cur.X.Y][cur.Y] + 1;
                q.push({{nx,ny},cur.Y});
            }
        }
    }
    if(!check) cout << -1;
}
