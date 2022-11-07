#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[4][3]={{'E','I'},{'S','N'},{'T','F'},{'J','P'}};
    int check[4]={};
    string a; cin >> a;
    if(a[0]=='E') check[0]=1;
    if(a[1]=='S') check[1]=1;
    if(a[2]=='T') check[2]=1;
    if(a[3]=='J') check[3]=1;
    for(int i=0;i<4;i++) cout << s[i][check[i]];


}