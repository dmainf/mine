#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define irep(i,n) for(int i=0;i<=(n);i++)
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
using vc=vt<int>;
using vv=vvt<int>;
using vvv=vvvt<int>;
using pi=pair<ll,ll>;
template<class T>istream& operator>>(istream& i,vt<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vt<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vt<vt<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
const int INF=1e9;
//const ll INF=1e18;
#include <atcoder/dsu>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    map<ll, int> mp;
    vt<pi> edge;
    int cnt=0;
    rep(i, n) {
        ll x, r; cin >> x >> r;
        auto get_id=[&](ll x) {
            if(!mp.count(x)) mp[x]=cnt++;
            return mp[x];
        };
        int u=get_id(x-r);
        int v=get_id(x+r);
        edge.pb({u, v});
    }
    dsu uf(cnt);
    for(auto [u, v]:edge) uf.merge(u, v);

    int ans=0;
    map<int, int> edge_cnt;
    for(auto [u, v]:edge) {
        int root=uf.leader(u);
        edge_cnt[root]++;
    }
    rep(i, cnt) if(uf.leader(i)==i) {
        int n_node=uf.size(i);
        int n_edge=edge_cnt[i];
        ans+=min(n_node, n_edge);
    }
    cout << ans << endl;

    return 0;
}