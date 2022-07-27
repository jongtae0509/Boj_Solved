#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    while(1){
        int a,b; cin >> a >> b;
        if(a==0&&b==0) break;
        if(a>b) cout << "Yes";
        else cout << "No";
        puts("");
    }
}
