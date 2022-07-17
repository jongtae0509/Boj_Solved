#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char s[9]={},s1[9]={};
	int k,cnt=0;
	while(1){
		cin >> s;
		k=strlen(s)-1;
		if(s[0]=='0') return 0;
		for(int i=0;s[i]!=NULL;i++){
			if(s[i]!=s[k])	cnt++;
			k--;
		}
		if(cnt==k+1) cout << "yes\n";
		else cout << "no\n";
		cnt=0;
	}
}