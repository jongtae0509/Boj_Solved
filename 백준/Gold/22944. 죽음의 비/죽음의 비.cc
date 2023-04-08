#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main() {
    int n,h,d; cin >> n >> h >> d;
    string mp[500];
    queue<pair<pair<int,int>,pair<pair<int,int>,int>>> q;
    int hp[500][500]={};
    for(int i=0;i<n;i++) cin >> mp[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mp[i][j]=='S'){
                hp[i][j]=h;
                q.push({{i,j},{{h,0},0}});
            }
        }
    }

    bool check=true;
    while(!q.empty()&&check){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X.X+dx[dir];
            int ny = cur.X.Y+dy[dir];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            int cnt=cur.Y.Y,nh=cur.Y.X.X,nd=cur.Y.X.Y;
            if(mp[nx][ny]=='E') {
                check = false;
                cout << cnt+1;
                break;
            }
            if(mp[nx][ny]=='U') nd=d;
            if(nd<=0) nh--;
            else nd--;
            if(nh==0) continue;
            if(hp[nx][ny]<nh){
                hp[nx][ny]=nh;
                q.push({{nx,ny},{{nh,nd},cnt+1}});
            }
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dist[i][j];
        }
        cout << '\n';
    }
     */
    if(check) cout<<-1;
}


