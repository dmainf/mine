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
#include <atcoder/modint>
using namespace atcoder;
using mint=modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<char> c(n);
    rep(i, n) cin >> c[i];
    vector<vector<int>> G(n);
    vector<pi> edge(n-1);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[i]={a, b};
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //dp[][c]
    //c==0 only 'a'
    //c==1 only 'b'
    //c==2 both
    vector<vector<mint>> dp(n, vector<mint>(3, 0));
    auto dfs=[&](auto dfs, int v, int p) -> void {
        mint val1=1, val2=1;
        for(int nv:G[v]) if(nv!=p) {
            dfs(dfs, nv, v);
            //val1  only 'a' or 'b'
            //val2  only 'a' + both
            if(c[v]=='a') {
                val1*=dp[nv][0]+dp[nv][2];
                val2*=dp[nv][0]+dp[nv][1]+2*dp[nv][2];
            }
            if(c[v]=='b') {
                val1*=dp[nv][1]+dp[nv][2];
                val2*=dp[nv][0]+dp[nv][1]+2*dp[nv][2];
            }
        }
        if(c[v]=='a') {
            dp[v][0]=val1;
            dp[v][2]=val2-val1;
        }
        if(c[v]=='b') {
            dp[v][1]=val1;
            dp[v][2]=val2-val1;
        }
    };
    dfs(dfs, 0, -1);
    cout << dp[0][2].val() << endl;

    return 0;
}