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
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(n, -1);
    dist[0]=0;
    auto dfs=[&](auto dfs, int v, int p=-1) -> void {
        for(int nv:G[v]) if(nv!=p) {
            dist[nv]=dist[v]+1;
            dfs(dfs, nv, v);
        }
    };
    dfs(dfs, 0);
    int mx=-1;
    int start=0;
    rep(i, n) {
        if(mx<dist[i]) {
            mx=dist[i];
            start=i;
        }
    }
    dist.assign(n, -1);
    dist[start]=0;
    dfs(dfs, start);
    int ans=-1;
    rep(i, n) ans=max(ans, dist[i]);
    cout << ans+1 << endl;

    return 0;
}