#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int mp[50][50];
    int dist[50][50];
    int n; cin >> n;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin >> c;
            mp[i][j] = c-'0';
            dist[i][j] = 999999999;
        }
    }
    q.push({0,0});
    dist[0][0]=0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0;dir < 4; dir++){
            int nx = dx[dir]+cur.X;
            int ny = dy[dir]+cur.Y;
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(mp[nx][ny]==1){
                if(dist[nx][ny]>dist[cur.X][cur.Y]){
                    dist[nx][ny]=dist[cur.X][cur.Y];
                    q.push({nx,ny});
                }
            }
            else{
                if(dist[nx][ny]>dist[cur.X][cur.Y]){
                    dist[nx][ny]=dist[cur.X][cur.Y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << dist[n-1][n-1];
}