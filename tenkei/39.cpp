#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define irep(i,n) for(ll i=0;i<=(n);i++)
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
template<class T>using vt=vector<T>;
template<class T>using vvt=vt<vt<T>>;
template<class T>using vvvt=vvt<vt<T>>;
using vc=vt<ll>;
using vv=vvt<ll>;
using vvv=vvvt<ll>;
using pi=pair<ll,ll>;
template<class T>istream& operator>>(istream& i,vt<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vt<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vt<vt<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
const ll INF=1e9;
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vv G(n);
    rep(i, n-1) {
        ll a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    vc dist(n, 0);
    auto dfs=[&](auto dfs, ll v, ll p=-1) -> void {
        dist[v]=1;
        for(ll nv:G[v]) if(nv!=p) {
            dfs(dfs, nv, v);
            dist[v]+=dist[nv];
        }
    };
    dfs(dfs, 0);
    ll ans=0;
    //全ペアの距離の総和 = 各辺を通る最短パスの数の総和
    rep(v, n) for(ll nv:G[v]) if(dist[nv]<dist[v]) {
        ans+=dist[nv]*(n-dist[nv]);
    }
    cout << ans << endl;

    return 0;
}