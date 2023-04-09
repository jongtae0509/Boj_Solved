#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ax[100001];
    long long ay[100001];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ax[i] = x;
        ay[i] = y;
    }
    ax[n] = ax[0];
    ay[n] = ay[0];
    long double f=0, s=0,ans;
    for(int i = 0; i < n; i++) f += ax[i] * ay[i + 1];
    for(int i=n;i>0;i--) s+= ax[i]*ay[i-1];
    ans=abs(f-s);
    printf("%.1LF",ans/2);
}
