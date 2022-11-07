#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
    int dist[1000][1000][2]={};
    char mp[1001][1001]={};
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mp[i][j];
            dist[i][j][0] = -1;
            dist[i][j][1] = -1;
        }
    }
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    while (!q.empty()){
        int x,y,check;
        tie(x,y,check) = q.front();
        if(x==n-1&&y==m-1){
            cout << dist[x][y][check];
            return 0;
        }
        q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = dx[dir] + x;
            int ny = dy[dir] + y;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(mp[nx][ny]=='0'&&dist[nx][ny][check]==-1){
                dist[nx][ny][check] = dist[x][y][check] + 1;
                q.push({nx,ny,check});
            }
            if(!check&&mp[nx][ny]=='1'&&dist[nx][ny][check]==-1){
                dist[nx][ny][1] = dist[x][y][check] + 1;
                q.push({nx,ny,1});
            }
        }
    }
    /*cout << '\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dist[i][j][1] << ' ';
        }
        cout << '\n';
    }*/
    cout << -1;
}