#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, int> p[200000];
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    int cnt = 0, MAX = 0;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cnt++;
        q.push(-p[i].second);
        while (p[i].first >= -q.top()) {
            cnt--;
            q.pop();
        }
        MAX = max(MAX, cnt);
    }
    cout << MAX;
}