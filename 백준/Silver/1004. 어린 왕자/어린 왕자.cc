#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; 
    while(t--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int n; cin >> n;
        int cnt = 0;
        while(n--){
            int cx, cy, r, tmp; cin >> cx >> cy >> r;
            bool a, b;
            tmp = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
            if(tmp>r*r) a = false;
            else a = true;
            tmp = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);
            if(tmp>r*r) b = false;
            else b = true;
            if (a != b) cnt++;
        }
        cout << cnt << "\n";
    }
}