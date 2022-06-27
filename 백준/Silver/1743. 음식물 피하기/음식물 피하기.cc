#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int n,m,k; cin >> n >> m >> k;
    char s[102][102]={};
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) s[i][j]='.';
    for(int i=0;i<k;i++){
        int x,y; cin >> x >> y;
        s[x-1][y-1] = '#';
    }
    bool vis[101][101]={};
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt = 0;
            if(s[i][j]=='#'&&!vis[i][j]){
                vis[i][j] = 1;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = dx[dir]+cur.X;
                        int ny = dy[dir]+cur.Y;
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(vis[nx][ny]||s[nx][ny]!='#') continue;
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                        cnt++;
                    }
                }
            }
            ans = max(cnt,ans);
        }
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout << s[i][j];
//        }
//        cout << '\n';
//    }
    cout << ans+1;
}