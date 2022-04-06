#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b; cin >> a >> b;
    int cnta=0,cntb=0;
    for(int i=0;i<a.size();i++) if(a[i]=='1') cnta++;
    for(int i=0;i<b.size();i++) if(b[i]=='1') cntb++;

    if(cnta>=cntb) cout << "VICTORY";
    else if(cnta<cntb){
        if(cnta%2==1&&(cnta+1==cntb)) cout << "VICTORY";
        else cout << "DEFEAT";
    }
}