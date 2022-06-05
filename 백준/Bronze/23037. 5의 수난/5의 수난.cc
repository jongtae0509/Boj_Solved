#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int sum=0;
    while(n!=0){
        sum+=pow(n%10,5);
        n/=10;
    }
    cout << sum;
}