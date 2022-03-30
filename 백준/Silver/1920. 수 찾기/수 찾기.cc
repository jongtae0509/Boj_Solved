#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m,a[100000],t;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> t;
		if(binary_search(a,a+n,t)) cout << "1\n";
		else cout << "0\n";
	}
	
}