#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1) {
        char s[251] = {};
        fgets(s, 252, stdin);
        int a[26] = {};
        for (int i = 0; i < strlen(s) - 1; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') a[s[i] - 'a'] = 1;
            if (s[i] >= 'A' && s[i] <= 'Z') a[s[i] - 'A'] = 1;
        }
        if (s[0] == '#' && strlen(s) == 2) break;
        int t=0;
        for(int i=0;i<26;i++) if(a[i]==1) t++;
        cout << t << '\n';
    }

}