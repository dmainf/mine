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
    auto bfs=[&](int s) {
       int n=G.size();
       vector<ll> dist(n, -1);
       queue<int> q;
       dist[s]=0;
       q.push(s);
       while(!q.empty()) {
           int v=q.front(); q.pop();
           for(int nv:G[v]) {
               if(dist[nv]!=-1) continue;
               dist[nv]=dist[v]+1;
               q.push(nv);
           }
       }
       return dist;
    };
    auto d0=bfs(0);
    ll mx=-1;
    vector<int> S1;
    rep(i, n) {
        if(d0[i]>mx){
            mx=d0[i];
            S1.clear();
            S1.push_back(i);
        } else if(d0[i]==mx){
            S1.push_back(i);
        }
    }
    int u=*max_element(S1.begin(), S1.end());
    auto du=bfs(u);
    mx=-1;
    vector<int> S2;
    rep(i, n) {
        if(du[i]>mx){
            mx=du[i];
            S2.clear();
            S2.push_back(i);
        } else if(du[i]==mx) S2.push_back(i);
    }
    int v=*max_element(S2.begin(), S2.end());
    auto dv=bfs(v);
    rep(i, n) {
        if(du[i]>dv[i]) cout << u+1 << endl;
        else if(du[i]<dv[i]) cout << v+1 << endl;
        else cout << max(u, v)+1 << endl;
    }

    return 0;
}