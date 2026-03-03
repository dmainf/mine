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
    int t; cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        vector<vector<int>> G(n);
        rep(i, m) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            G[u].push_back(v);
        }
        // dp[v][turn]
        //頂点v、残りターンturnのときAliceが勝つかどうか
        vector<vector<int>> dp(n, vector<int>(2*k+1, -1));
        auto dfs=[&](auto dfs, int v, int turn) -> bool {
            if(turn==0) return (s[v]=='A');
            if(dp[v][turn]!=-1) return dp[v][turn];
            bool res;
            if(turn%2==0) { //Alice
                res=false;
                for(int nv:G[v]) if(dfs(dfs, nv, turn-1)) {
                    res=true;
                    break;
                }
            } else { //Bob
                res=true;
                for(int nv:G[v]) if(!dfs(dfs, nv, turn-1)) {
                    res=false;
                    break;
                }
            }
            return dp[v][turn]=res;
        };
        bool alice_win=dfs(dfs, 0, 2*k);
        if(alice_win) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }

    return 0;
}