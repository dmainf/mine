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
//const int INF=1e9;
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<tuple<ll, ll, ll>> part(n);
    rep(i, n) {
        int w, h, b; cin >> w >> h >> b;
        part[i]={w, h, b};
    }
    const ll OFFSET=500*n;
    const ll MAX=2*OFFSET+1;
    //dp[diff] when diff, max hapiness
    //diff=head-body
    vector<ll> dp(MAX, -INF);
    dp[OFFSET]=0;
    rep(i, n) {
        vector<ll> n_dp(MAX, -INF);
        auto [w, h, b]=part[i];
        rep(diff, MAX) {
            if(dp[diff]==-INF) continue;
            int to_head=diff+w;
            int to_body=diff-w;
            if(0<=to_head && to_head<MAX) n_dp[to_head]=max(n_dp[to_head], dp[diff]+h);
            if(0<=to_body && to_body<MAX) n_dp[to_body]=max(n_dp[to_body], dp[diff]+b);
        }
        dp=n_dp;
    }
    ll ans=-1;
    //head<=body
    for(int i=0; i<=OFFSET; i++) ans=max(ans, dp[i]);
    cout << ans << endl;

    return 0;
}