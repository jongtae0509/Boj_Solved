#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    int arr[300001]={};
    
    for(int i=1;i<=n;i++) cin >> arr[i];
    
	sort(arr+1,arr+n+1);
    
	for(int i=1;i<=n;i++) arr[i]+=arr[i-1];
	
	while(q--){
		int r,l; cin >> l >> r;
		cout << arr[r] - arr[l-1] << "\n";
	}
}
