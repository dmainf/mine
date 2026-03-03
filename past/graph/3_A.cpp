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
    vector<int> ord(n, -1); //order of visit
    vector<int> low(n, -1); //lowest order bia only back-edge
    vector<bool> is_art(n, false);
    int time=0;
    auto dfs=[&](auto dfs, int v, int p=-1) -> void {
        seen[v]=true;
        ord[v]=low[v]=time++;
        int child=0;
        for(int nv:G[v]) if(nv!=p) {
            //return directly to ancestor
            if(seen[nv]) low[v]=min(low[v], ord[nv]);
            //return to ancestor bia child or can't return
            else {
                child++;
                dfs(dfs, nv, v);
                low[v]=min(low[v], low[nv]);
                //root and 2 child
                if(p==-1 && 2<=child) is_art[v]=true;
                //not root and no back-edge
                if(p!=-1 && ord[v]<=low[nv]) is_art[v]=true;
            }
        }
    };
    dfs(dfs, 0);
    rep(i, n) if(is_art[i]) cout << i << endl;

    return 0;
}