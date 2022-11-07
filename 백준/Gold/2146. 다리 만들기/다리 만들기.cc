#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int mp[100][100];
    int n; cin >> n;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];

        }
    }

    // 섬 번호
    bool b[100][100]={};
    int noi=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mp[i][j]==1&&!b[i][j]){
                b[i][j]=true;
                q.push({i,j});
                mp[i][j] = noi;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = dx[dir]+cur.X;
                        int ny = dy[dir]+cur.Y;
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(mp[nx][ny]==0||b[nx][ny]) continue;
                        mp[nx][ny]=noi;
                        b[nx][ny]=true;
                        q.push({nx,ny});
                    }

                }
                noi++;
            }
        }
    }
    int tmp = 987654321;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool vis[100][100]={};
            int dist[100][100]={};
            for(int k=0;k<n;k++) for(int t=0;t<n;t++) dist[k][t] = -1;
            if(mp[i][j]!=0){
                q.push({i,j});
                dist[i][j] = 0;

                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = dx[dir]+cur.X;
                        int ny = dy[dir]+cur.Y;
                        if(nx<0||nx>=n||ny<0||ny>=n) continue;
                        if(dist[nx][ny]>-1) continue;
                        dist[nx][ny] = dist[cur.X][cur.Y]+1;
                        q.push({nx,ny});
                    }
                }
                for(int k=0;k<n;k++) for(int t=0;t<n;t++) if(dist[k][t]>0&&(mp[i][j]!=mp[k][t]&&mp[k][t]!=0)) tmp = min(dist[k][t],tmp);
            }
        }
    }
    cout << tmp-1;
}