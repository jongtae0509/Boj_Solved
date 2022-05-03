#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[2000]={},cnt=0;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int s=0,e=n-1,sum;
        while(s<e){
            sum=arr[s]+arr[e];
            if(sum==arr[i]){
                if(s!=i&&e!=i){
                    cnt++;
                    break;
                }
                else if(s==i) s++;
                else if(e==i) e--;
            }
            else if(sum<arr[i]) s++;
            else e--;
        }
    }
    cout << cnt;
}