#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int i=0;
	char a[1000001]={};
	fgets(a,1000001,stdin);
	int sum=0;
	for(i=0;i<strlen(a);i++){
		if(i!=strlen(a)-2&&i!=0&&a[i]==' ') sum++;
	}
	if(a[0]==' '&&strlen(a)==2){
		cout << 0;
		return 0;
	}
	if(a[0]=='\n'&&strlen(a)==1){
		cout << 0;
		return 0;
	}
	cout << sum+1;
}