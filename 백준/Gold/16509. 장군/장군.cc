#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[8]={3,3,-3,-3,2,-2,2,-2};
int dy[8]={-2,2,-2,2,3,3,-3,-3};

bool check(int i,int x, int y,int nx,int ny){
    if(i==0||i==6){
        for(int j=1;j<3;j++){
            if(x-j==nx&&y+j==ny) return 1;
        }
    }
    else if(i==1||i==4){
        for(int j=1;j<3;j++){
            if(x-j==nx&&y-j==ny) return 1;
        }
    }
    else if(i==2||i==7){
        for(int j=1;j<3;j++){
            if(x+j==nx&&y+j==ny) return 1;
        }
    }
    else if(i==5||i==3){
        for(int j=1;j<3;j++){
            if(x+j==nx&&y-j==ny) return 1;
        }
    }
    return 0;
}
int main(){
    pair<int,int> king;
    pair<int,int> sang;
    cin >> sang.X >> sang.Y;
    cin >> king.X >> king.Y;

    int dist[100][100]={};
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            dist[i][j]=-1;
        }
    }
    queue<pair<int,int> > q;
    q.push({sang.X,sang.Y});
    dist[sang.X][sang.Y] = 0;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int dir=0;dir<8;dir++){
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;
            if(nx<0||nx>9||ny<0||ny>8) continue;
            if(dist[nx][ny]>-1) continue;
            if(check(dir,nx,ny,king.X,king.Y)) continue;
            if(nx==king.X&&ny==king.Y){
                cout << dist[cur.X][cur.Y] + 1;
                return 0;
            }
            q.push({nx,ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    cout << -1;
//	cout << '\n';
//	for(int i=0;i<10;i++){
//		for(int j=0;j<9;j++){
//			cout << dist[i][j] << ' ';
//		}
//		cout << '\n';
//	}
}