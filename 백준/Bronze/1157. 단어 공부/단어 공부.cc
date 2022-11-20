#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct a{
	int a,b;
};
bool cmp(const a &u,const a &v){
	return u.a>v.a;
}
int main(){
	string s;
	struct a check[130]={};
	for(int i=0;i<130;i++){
		check[i].b=i;
	}
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z') check[s[i]+32].a++;
		else check[s[i]].a++;
	}
	sort(check,check+130,cmp);
	if(check[0].a==check[1].a) cout << "?";
	else printf("%c",check[0].b-32);
}