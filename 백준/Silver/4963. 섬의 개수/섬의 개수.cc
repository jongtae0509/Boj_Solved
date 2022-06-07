#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;


int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
int dy[8] = {0, 1, 0, -1,1,-1,1,-1};

int main() {
    while(1){
        int mp[50][50]={};
        bool vis[50][50]={};
        int cnt = 0;
        queue<pair<int,int>> q;
        int w,h; cin >> w >> h;
        if(w==0&&h==0) break;
        for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> mp[i][j];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!vis[i][j]&&mp[i][j]==1){
                    vis[i][j] = 1;
                    q.push({i,j});
                    while(!q.empty()){
                        auto cur = q.front(); q.pop();
                        for(int dir=0;dir<8;dir++){
                            int nx = dx[dir]+cur.X;
                            int ny = dy[dir]+cur.Y;
                            if(nx<0||nx>=h||ny<0||ny>=w) continue;
                            if(mp[nx][ny]==0||vis[nx][ny]) continue;
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                    cnt++;
                }
            }
        }
    cout << cnt << '\n';
    }
}