#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dist1[50][50];
int dist2[50][50];
queue<pair<int,int>> q1,q2;
char m[51][51];

int main(){
    int r,c; cin >> r >> c;
    for(int i=0;i<r;i++){
        fill(dist1[i],dist1[i]+c,-1);
        fill(dist2[i],dist2[i]+c,-1);
    }
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> m[i][j];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(m[i][j]=='*'){
                dist1[i][j]=0;
                q1.push({i,j});
            }
            if(m[i][j]=='S'){
                dist2[i][j]=0;
                q2.push({i,j});
            }
        }
    }

    while(!q1.empty()){
        auto cur = q1.front(); q1.pop();
        for(int dir=0;dir<4;dir++){
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;
            if(nx<0||nx>=r||ny<0||ny>=c) continue;
            if(m[nx][ny]!='.'||dist1[nx][ny]>=0) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            q1.push({nx,ny});
        }
    }
    while(!q2.empty()){
        auto cur = q2.front(); q2.pop();
        for(int dir=0;dir<4;dir++){
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;
            if(nx<0||nx>=r||ny<0||ny>=c) continue;
            if(m[nx][ny]=='D'){
                cout << dist2[cur.X][cur.Y]+1;
                return 0;
            }
            if((m[nx][ny]!='.'&&m[nx][ny]!='D')||dist2[nx][ny]>=0) continue;
            if(dist1[nx][ny]!=-1&&(dist2[cur.X][cur.Y]+1>=dist1[nx][ny])) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            q2.push({nx,ny});
        }
//        for(int i=0;i<r;i++){
//            for(int j=0;j<c;j++){
//                cout << dist2[i][j];
//            }
//            cout << "\n";
//        }
//        cout << "\n";
    }
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            cout << dist1[i][j];
//        }
//        cout << "\n";
//    }
//    cout << "\n";
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            cout << dist2[i][j];
//        }
//        cout << "\n";
//    }
    cout << "KAKTUS";
}