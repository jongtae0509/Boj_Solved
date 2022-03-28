#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int m; cin >> m;
    long long int sum = 0, xol=0;
    while(m--){
        int a; cin >> a;
        if(a==1){
            int t; cin >> t;
            sum+=t;
            xol^=t;
        }
        else if(a==2){
            int t; cin >> t;
            sum-=t;
            xol^=t;
        }
        else if(a==3){
            cout << sum << "\n";
        }
        else{
            cout << xol << "\n";
        }
    }
}
