#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define irep(i, n) for(ll i=0; i<=(n); i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {YES}else{NO}
#define dame cout<<-1<<endl
using ll=long long;
template<class T>using vc=vector<T>;
template<class T>using vvc=vc<vc<T>>;
template<class T>using vvvc=vvc<vc<T>>;
using vi=vc<ll>;
using vv=vvc<ll>;
using vvv=vvvc<ll>;
using pi=pair<ll,ll>;
template<class T>istream& operator>>(istream& i,vc<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vc<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vc<vc<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
//const ll INF=1e9;
const ll INF=1e18;
#include <atcoder/segtree>
using namespace atcoder;
ll op(ll a, ll b) { return max(a, b); }
ll e() { return -1; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll w, n; cin >> w >> n;
    vc<tuple<ll,ll,ll>> cuisin(n);
    rep(i, n) {
        ll l, r, v; cin >> l >> r >> v;
        cuisin[i]={v, l, r};
    }
    vi dp(w+1, -1LL);
    dp[0]=0;
    for(auto [v, l, r]:cuisin) {
        segtree<ll, op, e> seg(w+1);
        irep(i, w) seg.set(i, dp[i]);
        auto ndp=dp;
        irep(i, w) {
            ll L=max(0LL, i-r), R=i-l;
            if(R<0) continue;
            ll mx=seg.prod(L, R+1);
            if(mx==-1) continue;
            ndp[i]=max(ndp[i], mx+v);
        }
        dp=ndp;
    }
    cout << dp[w] << endl;

    return 0;
}