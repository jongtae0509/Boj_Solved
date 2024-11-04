#include <bits/stdc++.h>
using namespace std;


int d(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    vector<bool> self(10001, false);
    for (int i = 1; i <= 10000; i++) {
        int n = d(i);
        if (n <= 10000) {
            self[n] = true;
        }
    }
    for (int i = 1; i <= 10000; i++) {
        if (!self[i]) {
            cout << i << '\n';
        }
    }
}