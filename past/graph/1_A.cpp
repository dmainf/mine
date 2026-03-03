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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, E, r;
    cin >> n >> E >> r;
    vector<vector<pi>> G(n);
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({d, t});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, r});
    vector<int> dist(n, INF);
    dist[r]=0;
    while(!pq.empty()) {
        auto [w, v]=pq.top();
        pq.pop();
        if(dist[v]!=w) continue;
        for(auto [nw, nv]:G[v]) {
            nw+=w;
            if(dist[nv]>nw) {
                dist[nv]=nw;
                pq.push({nw, nv});
            }
        }
    }
    for(int x:dist) {
        if(x==INF) cout << "INF" << endl;
        else cout << x << endl;
    }

    return 0;
}