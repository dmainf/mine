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
        G[t].push_back(s);
    }
    vector<bool> seen(n, false);
    vector<int> ord(n, -1), low(n, -1);
    vector<pi> bridge;
    int time=0;
    auto dfs=[&](auto dfs, int v, int p=-1) -> void {
        seen[v]=true;
        ord[v]=low[v]=time;
        time++;
        for(int nv:G[v]) if(nv!=p) {
            if(seen[nv]) low[v]=min(low[v], ord[nv]);
            else {
                dfs(dfs, nv, v);
                low[v]=min(low[v], low[nv]);
                if(ord[v]<low[nv]) {
                    int s=min(v, nv);
                    int t=max(v, nv);
                    bridge.push_back({s, t});
                }
            }
        }
    };
    dfs(dfs, 0);
    sort(all(bridge));
    for(auto [s, t]:bridge) cout << s << " " << t << endl;

    return 0;
}