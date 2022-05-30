#include <bits/stdc++.h>

using namespace std;

int main(){
    string a,b; cin >> a >> b;
    int arr[4001][4001]={};
    int Max = 0;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
                Max = max(Max,arr[i][j]);
            }
        }
    }
    cout << Max;
}