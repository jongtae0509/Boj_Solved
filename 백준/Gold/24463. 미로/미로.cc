#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    char mp[3000][3000]={};
    int dist[3000][3000]={};
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mp[i][j];
            dist[i][j]=-1;
        }
    }
    bool c = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0||j==0||i==n-1||j==m-1)&&mp[i][j]=='.'){
                q.push({i,j});
                dist[i][j]=0;
                c = true;
                break;
            }
        }
        if(c) break;
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0;dir < 4; dir++){
            int nx = dx[dir]+cur.X;
            int ny = dy[dir]+cur.Y;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(mp[nx][ny]!='.'||dist[nx][ny]>-1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i==0||j==0||i==n-1||j==m-1)&&dist[i][j]>0){
                q.push({i,j});
                mp[i][j]='@';
                c = false;
                break;
            }
            if(!c) break;
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0;dir < 4; dir++){
            int nx = dx[dir]+cur.X;
            int ny = dy[dir]+cur.Y;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(mp[nx][ny]!='.'||dist[nx][ny]>dist[cur.X][cur.Y]) continue;
            mp[nx][ny] = '@';
            q.push({nx,ny});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='.') cout << '@';
            else if(mp[i][j]=='@') cout << '.';
            else cout << mp[i][j];
        }
        cout << '\n';
    }
}