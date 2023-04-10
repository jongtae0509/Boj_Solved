#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main() {
    int mp[100][100]={};
    int Max=0;
    int sum=0;
    int n,m; cin >> n >> m;
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        string s; cin >> s;
        for(int j=1;j<=m;j++){
            mp[i][j]=s[j-1]-'0';
            Max=max(mp[i][j],Max);
        }
    }
    for(int h=1;h<=Max;h++){
        mp[0][0]=h;
        q.push({0,0});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.X+dx[dir];
                int ny = cur.Y+dy[dir];
                if(nx<0||ny<0||nx>n+1||ny>m+1) continue;
                if(mp[nx][ny]>=h) continue;
                mp[nx][ny]=h;
                q.push({nx,ny});
            }
        }
        /*
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                cout << mp[i][j];
            }
            cout << '\n';
        }
         */
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]<h){
                    sum++;
                    mp[i][j]+=1;
                }
            }
        }
        //cout << sum << '\n';
    }
    cout << sum;
}
