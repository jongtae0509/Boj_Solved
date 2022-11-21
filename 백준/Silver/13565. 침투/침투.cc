#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
    char map[1001][1001]={};
    int n,m; cin >> m >> n;
    int a[1001][1001]={};
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin >> map[i][j];
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) a[i][j]=-1;

    for(int i=0;i<n;i++){
        if(map[0][i]=='0') {
            q.push({0, i});
            a[0][i] = 0;
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = dx[dir] + cur.X;
                    int ny = dy[dir] + cur.Y;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (a[nx][ny] > -1 || map[nx][ny] == '1') continue;
                    a[nx][ny] = a[cur.X][cur.Y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }*/

    for(int i=0;i<n;i++){
        if(a[m-1][i]>-1){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";


}

