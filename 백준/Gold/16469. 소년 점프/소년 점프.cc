#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    int dist1[100][100]={};
    int dist2[100][100]={};
    int dist3[100][100]={};
    char mp[100][100]={};
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mp[i][j];
            dist1[i][j]=dist2[i][j]=dist3[i][j]=-1;
        }
    }
    pair<int,int> a,b,c; cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y;
    queue<pair<int,int>> q;
    q.push({a.X-1,a.Y-1});
    dist1[a.X-1][a.Y-1]=0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X+dx[dir];
            int ny = cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(mp[nx][ny]=='1'||dist1[nx][ny]>-1) continue;
            q.push({nx,ny});
            dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
        }
    }
    q.push({b.X-1,b.Y-1});
    dist2[b.X-1][b.Y-1]=0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X+dx[dir];
            int ny = cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(mp[nx][ny]=='1'||dist2[nx][ny]>-1) continue;
            q.push({nx,ny});
            dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
        }
    }
    q.push({c.X-1,c.Y-1});
    dist3[c.X-1][c.Y-1]=0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X+dx[dir];
            int ny = cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(mp[nx][ny]=='1'||dist3[nx][ny]>-1) continue;
            q.push({nx,ny});
            dist3[nx][ny] = dist3[cur.X][cur.Y]+1;
        }
    }
    int mn = 1000000;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int mx = max(max(dist1[i][j],dist2[i][j]),dist3[i][j]);
            if(min(min(dist1[i][j],dist2[i][j]),dist3[i][j])!=-1){
                if(mn>mx){
                    mn = mx;
                    cnt = 1;
                }
                else if(mn==mx) cnt++;
            }
        }
    }
    if(cnt==0) cout << -1;
    else cout << mn << '\n' << cnt;
}
