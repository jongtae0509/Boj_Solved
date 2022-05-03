#include<bits/stdc++.h>
using namespace std;

int main() {
    int g; cin >> g;
    int s=1,e=1;
    bool check = 0;
    while(1){
        if((e-s)*(e+s)==g){
            check = 1;
            cout << e << "\n";
        }
        if(e-s==1&&(e-s)*(e+s)>g) break;
        if((e-s)*(e+s)<g) e++;
        else s++;
       // cout << e << ' ' << s << ' ' << (e-s)*(e+s) << '\n';
    }
    if(!check) cout << -1;
}