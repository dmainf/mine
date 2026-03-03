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
    vector<vector<int>> G(n);
    rep(i, m) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    vector<bool> seen(n, false);
    vector<int> topo;
    auto dfs=[&](auto dfs, int v) -> void {
        seen[v]=true;
        for(int nv:G[v]) if(!seen[nv]) {
            dfs(dfs, nv);
        }
        topo.push_back(v);
    };
    rep(i, n) if(!seen[i]) dfs(dfs, i);
    reverse(all(topo));
    for(int x:topo) cout << x << endl;

    return 0;
}