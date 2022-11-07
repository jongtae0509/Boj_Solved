#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

struct a{
    int mx;
    int sum;
};

bool cmp(const a &u,const a &v){
    if(u.mx!=v.mx) return u.mx>v.mx;
    else return u.sum>v.sum;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    int n,m; cin >> n >> m;
    int mp[50][50]={};
    struct a aa[100000]={};
    int cnt = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> mp[i][j];
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]!=0){
                int dist[50][50]={};
                for(int k=0;k<n;k++) for(int t=0;t<m;t++) dist[k][t]=-1;
                queue<pair<int,int>> q;
                q.push({i,j});
                dist[i][j]=0;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = dx[dir] + cur.X;
                        int ny = dy[dir] + cur.Y;
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(mp[nx][ny]==0||dist[nx][ny]>-1) continue;
                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        q.push({nx,ny});
                    }
                }
                int mx = 0;
                pair<int,int> xy;
                for(int a=0;a<n;a++){
                    for(int b=0;b<m;b++){
                        if(mx<dist[a][b]){
                            mx = dist[a][b];
                            xy.X = a;
                            xy.Y = b;
                        }
                    }
                }
                aa[cnt].mx = mx;
                aa[cnt].sum = mp[i][j]+mp[xy.X][xy.Y];
                cnt++;
            }
        }
    }
    sort(aa,aa+cnt,cmp);
    cout << aa[0].sum;
}