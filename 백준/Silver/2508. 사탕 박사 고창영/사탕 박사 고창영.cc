#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int r,c; cin >> r >> c;
        int cnt = 0;
        char map[401][401]={};
        for(int i=0;i<r;i++) cin >> map[i];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(map[i][j]=='o'){
                    if((i!=0||i!=r-1)&&(map[i-1][j]=='v'&&map[i+1][j]=='^')) cnt++;
                    else if((j!=0||j!=c-1)&&(map[i][j-1]=='>'&&map[i][j+1]=='<')) cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}
