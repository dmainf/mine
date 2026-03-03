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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n), rG(n);
    rep(i, m) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        rG[t].push_back(s);
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
    int q; cin >> q;
    vector<int> ans;
    while(q--) {
        int u, v; cin >> u >> v;
        ans.push_back(comp[u]==comp[v] ? 1:0);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}