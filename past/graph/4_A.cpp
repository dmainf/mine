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
    }
    vector<bool> seen(n, false), finished(n, false);
    auto dfs=[&](auto dfs, int v) -> bool {
        seen[v]=true;
        for(int nv:G[v]) {
            if(finished[nv]) continue;
            if(seen[nv] && !finished[nv]) return true;
            if(dfs(dfs, nv)) return true;
        }
        finished[v]=true;
        return false;
    };
    rep(i, n) if(!seen[i]) {
        if(dfs(dfs, i)) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}