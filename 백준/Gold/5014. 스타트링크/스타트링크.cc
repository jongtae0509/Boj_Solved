#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int f,s,g,u,d; cin >> f >> s >> g >> u >> d;
    int dist[1000001]={};
    fill(dist+1,dist+f+1,-1);
    queue <int> q;
    dist[s]=0;
    q.push(s);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto i : {cur+u,cur-d}){
            if(i>f||i<=0||dist[i]!=-1) continue;
            dist[i]=dist[cur]+1;
            q.push(i);
        }
    }
    if(dist[g]==-1) cout << "use the stairs";
    else cout << dist[g];
}