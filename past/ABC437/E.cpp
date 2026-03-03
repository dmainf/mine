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
    int n; cin >> n;
    vt<vt<pi>> adj(n + 1);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        adj[x].pb({y, i+1});
    }
    vc ans;
    auto dfs=[&](auto dfs, vc node) -> void {
        sort(all(node));
        for(int v:node) if(v!=0) {
            ans.pb(v);
        }
        vt<pi> child;
        for(int v:node) for(auto [y, v]:adj[v]) {
            child.pb({y, v});
        }
        if (child.empty()) return;
        sort(all(child));
        int m=child.size();
        int i=0;
        while(i<m) {
            int cur_y=child[i].first;
            vc n_group;
            while(i<m && child[i].first==cur_y) {
                n_group.pb(child[i].second);
                i++;
            }
            dfs(dfs, n_group);
        }
    };
    dfs(dfs, {0});
    cout << ans;

    return 0;
}