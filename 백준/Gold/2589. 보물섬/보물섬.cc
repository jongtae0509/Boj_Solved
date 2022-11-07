#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};

char mp[51][51];
int w,h;

int bfs(int a,int b){
    queue <pair<int,int>> q;
    int dist[50][50]={};
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) dist[i][j]=-1;
    q.push({a,b});
    dist[a][b]=0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=h||ny<0||ny>=w) continue;
            if(dist[nx][ny]!=-1) continue;
            if(mp[nx][ny]!='L') continue;
            q.push({nx,ny});
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
        }
    }
    int mx = 0;
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) mx = max(dist[i][j],mx);
    return mx;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> h >> w;
    int ans=1;
    for(int i=0;i<h;i++) cin >> mp[i];
    for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(mp[i][j]=='L') ans = max(ans,bfs(i,j));
    cout << ans;
    
}
