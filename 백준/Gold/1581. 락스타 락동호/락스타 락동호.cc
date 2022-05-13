#include<bits/stdc++.h>
using namespace std;

int main(){
    int ff, fs, sf, ss;
    cin >> ff >> fs >> sf >> ss;
    if (ff == 0 && fs == 0){
        if (sf == 0) cout << ss;
        else cout << ss+1;
    }
    else if (fs == 0) cout << ff;
    else{
        if (fs <= sf) cout << ff+fs*2+ss;
        else cout << ff+sf*2+ss+1;
    }
}