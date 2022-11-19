#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        if(s[0]>='a'&&s[0]<='z') s[0]-=32;
        cout << s;
        cout << '\n';

    }
}