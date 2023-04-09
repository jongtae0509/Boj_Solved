#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool used[10];
void f(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            arr[k]=i;
            used[i]=1;
            f(k+1);
            used[i]=0;
        }
    }
}
int main(){
    cin >> n >> m;
    f(0);
}