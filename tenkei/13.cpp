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
    vector<vector<pi>> G(n);
    rep(i, m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({c, b});
        G[b].push_back({c, a});
    }
    auto dijkstra=[&](int start) -> vector<int> {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, start});
        vector<int> dist(n, INF);
        dist[start]=0;
        while(!pq.empty()) {
            auto [w, v]=pq.top();
            pq.pop();
            if(dist[v]!=w) continue;
            for(auto [nw, nv]:G[v]) {
                nw+=w;
                if(dist[nv]<=nw) continue;
                dist[nv]=nw;
                pq.push({nw, nv});
            }
        }
        return dist;
    };
    vector<int> dist_f=dijkstra(0);
    vector<int> dist_b=dijkstra(n-1);
    rep(k, n) cout << dist_f[k]+dist_b[k] << endl;

    return 0;
}