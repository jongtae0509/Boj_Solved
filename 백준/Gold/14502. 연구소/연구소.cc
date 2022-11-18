#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int map[8][8]={},wall=0,vir=0,ma=0;
    vector<pair<int,int>> v;
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j]==0) v.push_back({i,j});
            else if(map[i][j]==1) wall++;
            else vir++;
        }
    }
    for(int a=0;a<v.size();a++){
        for(int b=a+1;b<v.size();b++){
            for(int c=b+1;c<v.size();c++) {
                map[v[a].X][v[a].Y] = 1;
                map[v[b].X][v[b].Y] = 1;
                map[v[c].X][v[c].Y] = 1;
                bool vis[8][8] = {};
                int cnt = vir;
                queue<pair<int,int>> q;
                for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if(map[i][j]==2) q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = dx[dir] + cur.X;
                        int ny = dy[dir] + cur.Y;
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(map[nx][ny]!=0||vis[nx][ny]) continue;
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                        cnt++;
                    }
                }
                ma = max(ma,n*m-(cnt+wall+3));
                map[v[a].X][v[a].Y] = 0;
                map[v[b].X][v[b].Y] = 0;
                map[v[c].X][v[c].Y] = 0;
            }
        }
    }
    cout << ma;
}