#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    int n,n2; cin >> n >> n2;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    for(int i=0;i<n2;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) {
        cout << v[i] << ' ';
    }

}