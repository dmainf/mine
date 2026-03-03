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
struct Edge {
    int weight, from, to;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, E, r;
    cin >> n >> E >> r;
    vector<Edge> edge(E);
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        edge[i]={d, s, t};
    }
    vector<int> dist(n, INF);
    dist[r]=0;
    rep(i, n-1) {
        for(auto [nw, v, nv]:edge) {
            if(dist[v]==INF) continue;
            dist[nv]=min(dist[nv], dist[v]+nw);
        }
    }
    for(auto [nw, v, nv]:edge) {
        if(dist[v]==INF) continue;
        if(dist[v]+nw<dist[nv]) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int x:dist) {
        if(x==INF) cout << "INF" << endl;
        else cout << x << endl;
    }

    return 0;
}