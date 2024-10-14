#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    int arr[300][300];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }
    int t; cin >> t;

    while(t--) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        int cnt=0;
        for(int i=a-1;i<c;i++) {
            for(int j=b-1;j<d;j++) {
                cnt+=arr[i][j];
            }
        }
        cout << cnt << "\n";
    }

}
