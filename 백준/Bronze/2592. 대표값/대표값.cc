#include <bits/stdc++.h>

using namespace std;

int main(){
    pair<int,int> a[1001]={};
    int sum=0;
    for(int i=0;i<10;i++){
        int t; cin >> t;
        a[t].first++;
        a[t].second = t;
        sum+=t;
    }
    sort(a,a+1000);
    cout << sum/10 << '\n' << a[999].second;
}