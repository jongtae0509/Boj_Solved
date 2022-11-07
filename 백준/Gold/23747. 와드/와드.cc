#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int r,c; cin >> r >> c;
    char mp[1100][1100]={};
    bool vis[1100][1100]={};
    char ans[1100][1100]={};
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> mp[i][j];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) ans[i][j]='#';
    int x,y; cin >> x >> y;
    x--;
    y--;
    queue<pair<int,int>> q;
    string s; cin >> s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='U') x--;
        else if(s[i]=='D') x++;
        else if(s[i]=='L') y--;
        else if(s[i]=='R') y++;
        else if(s[i]=='W'){
            q.push({x,y});
            vis[x][y]=true;
            ans[x][y]='.';
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx = dx[dir]+cur.X;
                    int ny = dy[dir]+cur.Y;
                    if(nx<0||nx>=r||ny<0||ny>=c) continue;
                    if(vis[nx][ny]||mp[nx][ny]!=mp[cur.X][cur.Y]) continue;
                    ans[nx][ny]='.';
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    ans[x][y]='.';
    for(int i=0;i<4;i++){
        int nx = dx[i]+x;
        int ny = dy[i]+y;
        if(nx<0||nx>=r||ny<0||ny>=c) continue;
        ans[nx][ny] = '.';
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << ans[i][j];
        }
        cout << '\n';
    }
}