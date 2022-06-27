#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int n,m[100][100]={}; cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> m[i][j];
    int max_ = 0;
    for(int h=0;h<=100;h++){
        bool vis[100][100]={};
        queue<pair<int,int>> q;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]>h&&!vis[i][j]){
                    vis[i][j]=1;
                    q.push({i,j});
                    while(!q.empty()){
                        auto cur = q.front(); q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx = cur.X+dx[dir];
                            int ny = cur.Y+dy[dir];
                            if(nx<0||nx>=n||ny<0||ny>=n) continue;
                            if(vis[nx][ny]||m[nx][ny]<=h) continue;
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                    cnt++;
                    max_ = max(cnt,max_);
                }
            }
        }
    }
    cout << max_;
}