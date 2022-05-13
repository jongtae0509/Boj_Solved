#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int t; cin >> t;
    while(t--){
        queue<pair<int,int>> q;
        double ans = 0;
        string map[100]={};
        bool vis[100][100]={};
        int h,w; cin >> h >> w;
        for(int i=0;i<h;i++) cin >> map[i];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j]=='s'){
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto cur = q.front(); q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx = dx[dir]+cur.X;
                            int ny = dy[dir]+cur.Y;
                            if(nx<0||nx>=h||ny<0||ny>=w) continue;
                            if(map[nx][ny]=='#'||vis[nx][ny]) continue;
                            ans++;
                            q.push({nx,ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        printf("%.2lf\n",ans);
    }
}