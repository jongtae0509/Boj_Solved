#include<bits/stdc++.h>
using namespace std;

int prime[4000001];

void Eratos(int n){
    if(n<=1) return;

    for(int i=2;i<=n;i++) prime[i]=i;
    for(int i=2;i*i<=n;i++){
        if(prime[i]==0) continue;
        for(int j=i*i;j<=n;j+=i) prime[j]=0;
    }
}
int main(){
    int n; cin >> n;
    int arr[2000000]={};
    int cnt = 0;
    Eratos(n);
    for(int i=2;i<=n;i++)
        if(prime[i]!=0) {
            arr[cnt] = i;
            cnt++;
        }
    int s=0,e=0,sum=0,cnt2=0;
    while(1){
        if(sum>n) sum-=arr[s++];
        else if(e==cnt) break;
        else sum+=arr[e++];

        if(sum==n) cnt2++;
    }
    cout << cnt2;
}