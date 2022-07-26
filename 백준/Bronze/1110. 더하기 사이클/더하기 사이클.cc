#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;


int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    int n; cin >> n;
    int t = n;
    int cnt=0;
    while(1){
        t=(t%10)*10+((t/10)+t%10)%10;
        cnt++;
        if(n==t) break;
    }
    cout << cnt;
}
