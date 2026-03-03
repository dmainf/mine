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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    rep(i, h) rep(j, w) if(s[i][j]=='#') {
        int cnt=0;
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#') cnt++;
        }
        if(!(cnt==2 || cnt==4)) {
            NO;
            return 0;
        }
    }
    YES;

    return 0;
}