#include <bits/stdc++.h>

using namespace std;

vector<int> p(10005,-1);

int find(int x){
    if(p[x]<0) return x;
    return p[x] = find(p[x]);
}
bool uni(int u, int v){
    u = find(u); v = find(v);
    if(u==v) return 0;
    if(p[u]>p[v]) swap(u,v);
    p[u]+=p[v];
    p[v]=u;
    return 1;
}

int main(){
    int v,e; cin >> v >> e;
    tuple<int,int,int> edge[100005];
    for(int i=0;i<e;i++){
        int a,b,c; cin >> a >> b >> c;
        edge[i]={c,a,b};
    }
    sort(edge,edge+e);
    int cnt=0,ans=0;
    for(int i=0;i<e;i++){
        int a,b,c;
        tie(c,a,b) = edge[i];
        if(!uni(a,b)) continue;
        ans+=c;
        cnt++;
        if(cnt==v-1) break;
    }
    cout << ans;
}