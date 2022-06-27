#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){
	return a+b>b+a;
}
int main(){
	int k,n; cin >> k >> n;
	string s = "";
	vector<string> v;
	for(int i=0;i<k;i++){
		string a; cin >> a;
		if(s.size()<a.size()||(s.size()==a.size()&&s<a)) s = a;
		v.push_back(a);
	}
	for(int i=0;i<n-k;i++) v.push_back(s);
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++) cout << v[i];
}