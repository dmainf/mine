#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const ll di[]={+1,-1,+0,+0};
const ll dj[]={+0,+0,+1,-1};
const ll INF=1e9;
//const ll INF=1e18;
const ll MAX=1e4;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll  n; cin >> n;
    ll a, b, c; cin >> a >> b >> c;
    ll ans=INF;
    rep(i, MAX) rep(j, MAX) if(i+j<=MAX) {
        ll tmp=a*i+b*j;
        tmp=n-tmp;
        if(tmp<0 || tmp%c!=0) continue;
        ll k=tmp/c;
        ans=min(ans, i+j+k);
    }
    cout << ans << endl;

    return 0;
}