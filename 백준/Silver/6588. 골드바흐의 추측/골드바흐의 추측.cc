#include<bits/stdc++.h>
using namespace std;

bool arr[1000001];
void era(){
    for(int i=2;i<1000000;i++) arr[i]=1;
    for(int i=2;i*i<1000000;i++){
        if(arr[i]) {
            for (int j = i * i; j < 1000000; j += i) {
                arr[j] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    era();
    int n,l,r;
    while(1){
        cin >> n;
        if(n==0) break;
        l = 3;
        r = n-3;
        while(l<=r){
            if(arr[l]&&arr[r]) if(l+r==n) break;
            l+=2;
            r-=2;
        }
        if(l>r) cout << "Goldbach's conjecture is wrong.";
        else cout << n<< " = " << l << " + " << r << '\n';
    }
}