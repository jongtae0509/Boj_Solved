#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[100000]={};
    int a[2];
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    int l=0,r=n-1,min = 2100000000;
    while(l<r){
        int sum = arr[l]+arr[r];
        if(abs(sum)<min) {
            min = abs(sum);
            a[0] = arr[l];
            a[1] = arr[r];
        }
        if(sum<0) l++;
        else if(sum==0) break;
        else r--;
    }
    cout << a[0] << " " << a[1];
}