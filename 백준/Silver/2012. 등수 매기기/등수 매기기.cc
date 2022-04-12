#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[500000];
    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr,arr+n);

    long long int sum = 0;
    for(int i=0;i<n;i++) sum+=abs((i+1)-arr[i]);

    cout << sum;
}
