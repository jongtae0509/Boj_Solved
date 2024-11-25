#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    string s;
    int aa=0;
    cin >> a >> s;
    for(auto i : s) {
        if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u') aa++;
    }
    cout << aa;
}
