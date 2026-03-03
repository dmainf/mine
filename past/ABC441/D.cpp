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
using pi=pair<int,int>;
template<class T>istream& operator>>(istream& i,vt<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vt<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vt<vt<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
const int INF=1e9;
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,l,s,t; cin >> n >> m >> l >> s >> t;
    vvt<pi> G(n);
    rep(i,m) {
        int u,v,c; cin >> u >> v >> c;
        u--; v--;
        G[u].pb({c,v});
    }
    vc ans;
    auto dfs=[&](auto dfs, int v, int depth, ll cost) {
        if(depth==l) {
            if(s<=cost && cost<=t) ans.push_back(v+1);
            return;
        }
        for(auto [ncost, nv]:G[v]) dfs(dfs, nv, depth+1, cost+ncost);
    };
    dfs(dfs, 0, 0, 0);
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << ans;

    return 0;
}