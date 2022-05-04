#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum1=0,sum2=0;
    for(int i=0;i<4;i++){
        int n; cin >> n;
        sum1+=n;
    }
    for(int i=0;i<4;i++){
        int n; cin >> n;
        sum2+=n;
    }
    cout << max(sum1,sum2);
}