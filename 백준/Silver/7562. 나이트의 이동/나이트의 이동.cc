#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;
int dx[8] = {1,-1,1,-1,2,2,-2,-2};
int dy[8] = {2,2,-2,-2,1,-1,1,-1};

int main(){
    int t; cin >> t;
    while(t--){
        int map[300][300] = {};
        bool vis[300][300] = {};
        queue<pair<int,int>> q;
        int l; cin >> l;
        pair<int,int> st; cin >> st.X >> st.Y; q.push({st.X,st.Y}); vis[st.X][st.Y] = 1;
        pair<int,int> des; cin >> des.X >> des.Y;
        bool ch=0;
        int ans=0;
        while(!q.empty()&&!ch){
            auto cur = q.front(); q.pop();
            for(int dir=0;dir<8;dir++){
                int nx = dx[dir] + cur.X;
                int ny = dy[dir] + cur.Y;
                if(nx<0||nx>=l||ny<0||ny>=l) continue;
                if(vis[nx][ny]||map[nx][ny]!=0) continue;
                if(nx==des.X&&ny==des.Y){
                    ch = 1;
                    ans = map[cur.X][cur.Y]+1;
                    break;
                }
                map[nx][ny] = map[cur.X][cur.Y]+1;
                q.push({nx,ny});
                vis[nx][ny] = 1;
            }
        }
//        for(int i=0;i<l;i++){
//            for(int j=0;j<l;j++){
//                cout << map[i][j] << ' ';
//            }
//            cout << '\n';
//        }
        cout << ans << '\n';
    }
}