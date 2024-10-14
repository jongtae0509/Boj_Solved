#include <bits/stdc++.h>
using namespace std;

int main() {
    deque <int> q;
    int n; cin >> n;
    for (int i=1;i<=n;i++) q.push_back(i);
    for(int i=0;i<n;i++) {
        cout << q.front() << " ";
        q.pop_front();
        q.push_back(q.front());
        q.pop_front();
    }
}
