#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[10]={};
    for(int i=0;i<3;i++) cin >> a[i];
    sort(a,a+3);
    cout << a[1];
}