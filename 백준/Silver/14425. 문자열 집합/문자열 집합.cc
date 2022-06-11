#include<bits/stdc++.h>

using namespace std;

map<string,bool> mp;

int main() {
    int n, m; cin >> n >> m;
    while(n--){
        string s; cin >> s;
        mp[s] = 1;
    }
    int cnt = 0;
    while(m--){
        string s; cin >> s;
        if(mp[s]) cnt++;
    }
    cout << cnt;
}