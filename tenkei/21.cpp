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
const int INF=1e9;
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n), rG(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        rG[b].push_back(a);
    }
    vector<bool> seen(n, false);
    vector<int> order;
    auto dfs=[&](auto dfs, int v) -> void {
        seen[v]=true;
        for(int nv:G[v]) if(!seen[nv]) {
            dfs(dfs, nv);
        }
        order.push_back(v);
    };
    rep(i, n) if(!seen[i]) {
        dfs(dfs, i);
    }
    vector<int> comp(n, -1);
    auto rdfs=[&](auto rdfs, int v, int id) -> void {
        comp[v]=id;
        for(int nv:rG[v]) if(comp[nv]==-1) {
            rdfs(rdfs, nv, id);
        }
    };
    int cnt=0;
    reverse(all(order));
    for(int v:order) if(comp[v]==-1) {
        rdfs(rdfs, v, cnt);
        cnt++;
    }
    map<int, int> mp;
    for(int x:comp) mp[x]++;
    ll ans=0;
    for(auto [num, x]:mp) {
        ans+=(ll)x*((ll)x-1LL)/2LL;
    }
    cout << ans << endl;

    return 0;
}