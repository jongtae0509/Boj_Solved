#include <bits/stdc++.h>
using namespace std;

int main() {
   pair<int,int> p[10];
   for(int i=1;i<=8;i++) {
      cin >> p[i].first;
      p[i].second = i;
   }
   sort(p,p+9);
   int a[5];
   int cnt=0;
   int j=0;
   for(int i=8;i>=4;i--) {
      a[j]=p[i].second;
      cnt+=p[i].first;
      j++;
   }
   sort(a,a+5);
   cout << cnt << '\n';
   for(int i=0;i<5;i++) cout << a[i] << ' ';

}
