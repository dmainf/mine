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
    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];
    ll ans=0;
    rep(i, h-1) rep(j, w-1) {
        int tmp=b[i][j]-a[i][j];
        ans+=abs(tmp);
        rep(ii, 2) rep(jj, 2) a[i+ii][j+jj]+=tmp;
    }
    if(a==b) {
        YES;
        cout << ans << endl;
    } else NO;

    return 0;
}