#include<bits/stdc++.h>

using namespace std;

struct a{
	int a,sum;
	string s;
};

bool cmp (const a &u, const a &v){
	if(u.a!=v.a) return u.a< v.a;
	else if((u.a==v.a)&&(u.sum!=v.sum)) return u.sum<v.sum;
	else return u.s<v.s;
}



int main(){
	struct a stc[50]={};
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin >> stc[i].s;
		stc[i].a = stc[i].s.size();
		for(int j=0;j<stc[i].s.size();j++){
			if(stc[i].s[j]>='0'&&stc[i].s[j]<='9') stc[i].sum+=stc[i].s[j]-'0';
		}
	}
	sort(stc,stc+n,cmp);
	for(int i=0;i<n;i++) cout << stc[i].s << '\n';
}