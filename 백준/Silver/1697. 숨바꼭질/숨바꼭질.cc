#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    int dist[100002];
    fill(dist,dist+100001,-1);
    dist[n]=0;
    queue<int> q;
    q.push(n);
    while(dist[k]==-1){
        int cur = q.front(); q.pop();
        for(int nxt : {cur-1,cur+1,cur*2}){
            if(nxt<0||nxt>100000) continue;
            if(dist[nxt]!=-1) continue;
            dist[nxt] = dist[cur]+1;
            q.push(nxt);
        }
    }
    cout << dist[k];
}