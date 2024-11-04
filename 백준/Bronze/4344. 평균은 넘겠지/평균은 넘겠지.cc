#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    while(n--) {
        int a[1000];
        int t; cin >> t;
        double avg=0;
        for(int i=0;i<t;i++) {
            cin >> a[i];
            avg+=a[i];
        }
        avg/=t;
        int cnt=0;
        for(int i=0;i<t;i++) {
            if(a[i]>avg) {
                cnt++;
            }
        }
        printf("%.3lf%%\n",double(cnt)*100/t);
    }

}