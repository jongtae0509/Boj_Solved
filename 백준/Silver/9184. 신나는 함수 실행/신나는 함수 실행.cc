#include<bits/stdc++.h>
using namespace std;

int aa[21][21][21];
int w(int a,int b,int c){
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) return w(20,20,20);
	else if(aa[a][b][c]!=0) return aa[a][b][c];
	else if(a<b&&b<c) aa[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else aa[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	
	return aa[a][b][c];
}

int main(){
	while(1){
		int a,b,c; cin >> a >> b >> c;
		if(a==-1&&b==-1&&c==-1) break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
}
