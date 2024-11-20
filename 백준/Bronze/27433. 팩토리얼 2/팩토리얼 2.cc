#include <bits/stdc++.h>
using namespace std;
long long int fac(long long int n) {
    if(n==1) return 1;
    if(n==0) return 1;
    return n*fac(n-1);
}
int main() {
     int n; cin >> n;
     cout << fac(n);
}