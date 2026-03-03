#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y;
    cin >> x >> y;
    int xx, yy;
    auto f=[&](string s) -> int {
        int res;
        if(s=="Ocelot") res=0;
        if(s=="Serval") res=1;
        if(s=="Lynx") res=2;
        return res;
    };
    xx=f(x);
    yy=f(y);
    if(yy<=xx) YES;
    else NO;

    return 0;
}