#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        if(s.size()>=6&&s.size()<=9) cout << "yes\n";
        else cout << "no\n";
    }
}
