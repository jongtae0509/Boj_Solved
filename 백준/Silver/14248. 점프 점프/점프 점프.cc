#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[100001]={};
    bool vis[100001]={};
    queue<int> q;
    int s;
    int n; cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> s;
    q.push(s-1);
    vis[s-1]= true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(0<=cur-a[cur]&&!vis[cur-a[cur]]){
            vis[cur-a[cur]] = true;
            q.push(cur-a[cur]);
        }
        if(cur+a[cur]<n&&!vis[cur+a[cur]]){
            vis[cur+a[cur]] = true;
            q.push(cur+a[cur]);
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++) if(vis[i]) cnt++;
    cout << cnt;

}