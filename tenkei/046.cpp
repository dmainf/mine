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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    //3
    //10 13 1
    //5 27 35
    //9 28 6
    vector<ll> a(46, 0), b(46, 0), c(46, 0);
    rep(i, n) { ll x; cin >> x; a[x%46]++; }
    rep(i, n) { ll x; cin >> x; b[x%46]++; }
    rep(i, n) { ll x; cin >> x; c[x%46]++; }
    ll ans=0;
    rep(i, 46) rep(j, 46) rep(k, 46) {
        if((i+j+k)%46==0) ans+=a[i]*b[j]*c[k];
    }
    cout << ans << endl;

    return 0;
}