#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int arr[400][400];
int n,m;

bool apart(){
    queue<pair<int,int> > q;
    bool vis[400][400]={};
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]>0&&!vis[i][j]){
                if(cnt!=0) return true;
                cnt++;
                q.push({i,j});
                vis[i][j] = true;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = dx[dir]+cur.X;
                        int ny = dy[dir]+cur.Y;
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(vis[nx][ny]||arr[nx][ny]==0) continue;
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> arr[i][j];
    int cnt = 0;
    bool check = true;
    queue<pair<int,int>> q;
    while(!apart()&&check){
        check = false;
        cnt++;
        bool vis[400][400]={};
        vector<pair<pair<int,int>,int>> v; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]>0&&!vis[i][j]){
                    check = true;
                    q.push({i,j});
                    vis[i][j] = true;
                    int count = 0;
            		for(int t=0;t<4;t++){
            			int nnx = i + dx[t];
            			int nny = j + dy[t];
            			if(nnx<0||nnx>=n||nny<0||nny>=m) continue;
            			if(arr[nnx][nny]==0) count++;
					}
					v.push_back({{i,j},count});
                    while(!q.empty()){
                    	auto cur = q.front(); q.pop();
                    	for(int dir=0;dir<4;dir++){
                    		int nx = dx[dir] + cur.X;
                    		int ny = dy[dir] + cur.Y;
                    		if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    		if(arr[nx][ny]==0||vis[nx][ny]) continue;
                    		count = 0;
                    		for(int t=0;t<4;t++){
                    			int nnx = nx + dx[t];
                    			int nny = ny + dy[t];
                    			if(nnx<0||nnx>=n||nny<0||nny>=m) continue;
                    			if(arr[nnx][nny]==0) count++;
							}
							v.push_back({{nx,ny},count});
                    		q.push({nx,ny});
                    		vis[nx][ny]=true;
						}
					}
					
                }
            }
        }
//        for(int i=0;i<v.size();i++){
//			printf("(%d,%d)-%d\n",v[i].X.X,v[i].X.Y,v[i].Y);
//		}
        for(int i=0;i<v.size();i++){
			arr[v[i].X.X][v[i].X.Y]-=v[i].Y;
			if(arr[v[i].X.X][v[i].X.Y]<0) arr[v[i].X.X][v[i].X.Y]=0;
		}
		
//        cout << '\n';
//        for(int i=0;i<n;i++){
//        	for(int j=0;j<m;j++){
//        		cout << arr[i][j] << ' ';
//			}
//			cout << '\n';
//		}
    }
    if(!check) cnt=0;
	cout << cnt;
}