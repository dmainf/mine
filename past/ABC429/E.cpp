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
    vector<vector<int>> G(n);
    vector<pi> edge;
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        edge.push_back({u, v});
        G[u].push_back(v);
        G[v].push_back(u);
    }
    string s; cin >> s;
    vector<int> dist1(n, INF), dist2(n, INF);
    vector<int> src1(n, -1), src2(n, -1);
    queue<pair<int, pi>> que;
    rep(i, n) if(s[i]=='S') {
        dist1[i]=0;
        src1[i]=i;
        que.push({i, {0, i}});
    }
    while(!que.empty()) {
        auto [v, tmp]=que.front();
        auto [d, src]=tmp;
        que.pop();
        if(!((dist1[v]==d && src1[v]==src) || (dist2[v]==d && src2[v]==src))) continue;
        for(int nv:G[v]) {
            int nd=d+1;
            bool flag=false;
            if(nd<dist1[nv]) {
                if(src1[nv]!=src) {
                    dist2[nv]=dist1[nv];
                    src2[nv]=src1[nv];
                }
                dist1[nv]=nd;
                src1[nv]=src;
                flag=true;
            } else if(src!=src1[nv] && nd<dist2[nv]) {
                dist2[nv]=nd;
                src2[nv]=src;
                flag=true;
            }
            if(flag) que.push({nv, {nd, src}});
        }
    }
    rep(i, n) if(s[i]=='D') {
        cout << (ll)dist1[i]+(ll)dist2[i] << endl;
    }

    return 0;
}