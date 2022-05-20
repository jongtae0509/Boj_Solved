#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dist[3000][3000];
queue<pair<int,int>> q;
string mp[3000];

int main(){
    int n,m; cin >> n >> m;
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<n;i++) cin >> mp[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='2'){
                dist[i][j]=0;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = dx[dir] + cur.X;
                        int ny = dy[dir] + cur.Y;
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(dist[nx][ny]>=0||mp[nx][ny]=='1') continue;
                        dist[nx][ny] = dist[cur.X][cur.Y]+1;
                        q.push({nx,ny});
                        if(mp[nx][ny]>'2'){
                            cout << "TAK\n" << dist[nx][ny];
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "NIE";
}