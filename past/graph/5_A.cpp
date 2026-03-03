#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<pi>> G(n);
    rep(i, n-1) {
        int s, t;
        ll w;
        cin >> s >> t >> w;
        G[s].push_back({w, t});
        G[t].push_back({w, s});
    }
    vector<ll> dist(n, -1);
    auto dfs=[&](auto dfs, ll w, int v, int p=-1) -> void {
        dist[v]=w;
        for(auto [nw, nv]:G[v]) if(nv!=p) {
            nw+=w;
            dfs(dfs, nw, nv, v);
        }
    };
    dfs(dfs, 0LL, 0);
    ll mx=-1;
    int start=0;
    rep(i, n) {
        if(mx<dist[i]) {
            mx=dist[i];
            start=i;
        }
    }
    dfs(dfs, 0LL, start);
    ll diameter=-1;
    rep(i, n) diameter=max(diameter, dist[i]);
    cout << diameter << endl;

    return 0;
}