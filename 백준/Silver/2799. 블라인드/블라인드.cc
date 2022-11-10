#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m; cin >> m >> n;
    int arr[5]={};
    char wd[1000][1000]={};
    for(int i=0;i<5*m+1;i++){
        for(int j=0;j<5*n+1;j++){
            cin >> wd[i][j];
        }
    }
    for(int i=1;i<5*m+1;i+=5){
        for(int j=1;j<5*n+1;j+=5) {
            int cnt = 0;
            for (int x=i; x<i+4; x++) {
                if(wd[x][j]=='*') cnt++;
            }
            for(int t=0;t<5;t++) if(cnt==t) arr[t]++;
        }
    }
    for(auto i:arr) cout << i << ' ';
}