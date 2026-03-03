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
    int n; cin >> n;
    vector<vector<int>> G(n);
    rep(i, n) {
        int k; cin >> k;
        rep(j, k) {
            int c; cin >> c;
            G[i].push_back(c);
        }
    }
    vector<int> dist(n, -1);
    dist[0]=0;
    auto dfs=[&](auto dfs, int v, int p=-1) -> void {
        parent[0][v]=p;
        for(int nv:G[v]) {
            dist[nv]=dist[v]+1;
            dfs(dfs, nv, v);
        }
    };
    dfs(dfs, 0);
    const int LOG=20;
    vector<vector<int>> parent(LOG, vector<int>(n, -1));
    //parent[k][v]  ノードvから2^k個上の祖先
    rep(k, LOG-1) {
        rep(v, n) {
            if(parent[k][v]<0) parent[k+1][v]=-1;
            else parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
    auto lca=[&](int u, int v) -> int {
        if(dist[u]<dist[v]) swap(u, v);
        //v-u
        int diff=dist[u]-dist[v];
        //To reduce Order, expressed diff by the power of 2
        rep(k, LOG) if(diff>>k&1) u=parent[k][u];
        //can get together depth
        if(u==v) return u;
        for(int k=LOG-1; k>=0; k--) {
            //when parent is different, move to one's parent
            if(parent[k][u]!=parent[k][v]) {
                u=parent[k][u];
                v=parent[k][v];
            }
        }
        return parent[0][u];
    };
    int q; cin >> q;
    vector<int> ans;
    while(q--) {
        int u, v; cin >> u >> v;
        ans.push_back(lca(u, v));
    }
    for(int x:ans) cout << x << endl;

    return 0;
}