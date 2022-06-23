#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    string s,s1; cin >> s >> s1;
    if(n%2==1){
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='0') s1[i]='1';
            else s1[i]='0';
        }
    }
    if(s==s1) cout << "Deletion succeeded";
    else cout << "Deletion failed";
}