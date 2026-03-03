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
    ll n, k; cin >> n >> k;
    vector<ll> a(1<<n, k/(1<<n));
    ll r=k%(1<<n);
    rep(i, r) {
        ll idx=0;
        //reverse bit
        rep(bit, n) if((i>>bit)&1) {
            idx|=(1<<(n-1-bit));
        }
        a[idx]++;
    }
    auto f=[&](vector<ll> a) {
        ll res=0;
        rep(i, n) {
            ll mx=*max_element(all(a));
            ll mn=*min_element(all(a));
            res=max(res, mx-mn);
            vector<ll> tmp;
            for(ll j=0; j<a.size(); j+=2) {
                tmp.push_back(a[j]+a[j+1]);
            }
            a=tmp;
        }
        return res;
    };
    cout << f(a) << endl;
    for(ll x:a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}