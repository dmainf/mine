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
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> G(n);
    rep(i, m) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back({w, t});
        G[t].push_back({w, s});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});
    vector<bool> seen(n, false);
    int ans=0;
    while(!pq.empty()) {
        auto [w, v]=pq.top();
        pq.pop();
        if(seen[v]) continue;
        seen[v]=true;
        ans+=w;
        for(auto [nw, nv]:G[v]) {
            if(seen[nv]) continue;
            pq.push({nw, nv});
        }
    }
    cout << ans << endl;

    return 0;
}