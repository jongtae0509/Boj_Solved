#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[4],b[2];
    for (int i = 0; i < 4; i++) cin >> a[i];
    sort(a, a + 4);
    for (int i = 0; i < 2; i++) cin >> b[i];
    sort(b, b + 2);
    cout << a[1] + a[2] + a[3] + b[1];
}