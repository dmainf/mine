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
    ll n, k;
    ll p;
    cin >> n >> k >> p;
    vector<ll> a1, a2;
    rep(i, n) {
        ll x; cin >> x;
        if(i%2==0) a1.push_back(x);
        else a2.push_back(x);
    }
    vector<vector<ll>> sum1(a1.size()+1), sum2(a2.size()+1);
    rep(i, (1<<a1.size())) {
        ll tmp=0;
        rep(bit, a1.size()) if((i>>bit)&1) {
            tmp+=a1[bit];
        }
        sum1[__builtin_popcount(i)].push_back(tmp);
    }
    rep(i, (1<<a2.size())) {
        ll tmp=0;
        rep(bit, a2.size()) if((i>>bit)&1) {
            tmp+=a2[bit];
        }
        sum2[__builtin_popcount(i)].push_back(tmp);
    }
    rep(i, sum2.size()) sort(all(sum2[i]));
    ll ans=0;
    rep(i, sum1.size()) {
        //sum2[]<=p-sum1[i]
        //sum1[i]+sum2[]<=p
        if(k-i<0 || sum2.size()<=k-i) continue;
        for(ll x:sum1[i]) {
            ll it=upper_bound(all(sum2[k-i]), p-x)-sum2[k-i].begin();
            ans+=it;
        }
    }
    cout << ans << endl;

    return 0;
}