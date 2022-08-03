#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

struct a{
    int na,stu,score;
};

bool cmp(const a &u, const a &v){
    return u.score>v.score;
}


int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
    struct a st[100];
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int na,stu,score;
        cin >> na >> stu >> score;
        st[i].na = na;
        st[i].stu = stu;
        st[i].score = score;
    }

    sort(st,st+n,cmp);
    int check[101]={};
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==3) break;
        if(check[st[i].na]==2) continue;
        cout << st[i].na << ' ' << st[i].stu << '\n';
        check[st[i].na]++;
        cnt++;
    }
}
