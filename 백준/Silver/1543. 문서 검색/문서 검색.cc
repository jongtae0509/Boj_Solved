#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[3000]={};
    char t[100]={};
    fgets(s,3000,stdin);
    fgets(t,100,stdin);
    int cnt=0;
    for(int i=0;i<strlen(s)-1;i++) {
        if(s[i]==t[0]) {
            bool ch=true;
            for(int j=0;j<strlen(t)-1;j++) {
                if(s[i+j]!=t[j]) {
                    ch=false;
                    break;
                }
            }
            if(ch) {
                cnt++;
                i+=strlen(t)-2;
            }
        }
    }
    cout<<cnt;
}
