#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--){
    	int x, y; cin >> x >> y;
    	int dis = y-x;
    	
    	int t = (int)sqrt(dis);
    	
    	if(t == sqrt(dis)) cout << t*2-1 << "\n";
    	else if(dis <= t*t+t) cout << t*2 << "\n";
    	else cout << t*2+1 << "\n";
	}
}
