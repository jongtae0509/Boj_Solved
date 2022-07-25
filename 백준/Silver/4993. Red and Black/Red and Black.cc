#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    while(1){
        int w,h; cin >> w >> h;
        int cnt = 1;
        if(w==0&&h==0) break;
        char map[20][20]={};
        bool vis[20][20]={};
        queue<pair<int,int>> q;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
                if(map[i][j]=='@'){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = dx[dir]+cur.X;
                int ny = dy[dir]+cur.Y;
                if(nx<0||ny<0||nx>=h||ny>=w) continue;
                if(vis[nx][ny]||map[nx][ny]=='#') continue;
                q.push({nx,ny});
                vis[nx][ny]=1;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}
