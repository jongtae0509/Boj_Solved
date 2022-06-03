#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    deque<pair<int,int>> d;
    int n,l; cin >> n >> l;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(!d.empty()&&d.front().second<=i-l) d.pop_front();
        while(!d.empty()&&d.back().first>a) d.pop_back();
        d.push_back({a,i});
        cout << d.front().first << ' ';
    }

}