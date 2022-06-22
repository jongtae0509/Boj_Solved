#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int n,m; cin >> n >> m;
    int b1[30][30]={},b2[30][30]={};
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> b1[i][j];
    bool check = 0;
    bool vis[30][30]={};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b2[i][j];
            if(b2[i][j]!=b1[i][j]) check = 1;
        }
    }

    if(!check){
        cout << "YES";
        return 0;
    }

    check = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(check) continue;
            if(b1[i][j]!=b2[i][j]&&!vis[i][j]){
                int t = b1[i][j];
                b1[i][j]=b2[i][j];
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = dx[dir] + cur.X;
                        int ny = dy[dir] + cur.Y;
                        if(nx<0||ny<0||nx>=n||ny>=m) continue;
                        if(t==b1[nx][ny]&&!vis[nx][ny]){
                            b1[nx][ny] = b2[i][j];
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
                check = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b1[i][j]!=b2[i][j]){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout << b2[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}