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
    vector<vector<pi>> G(n);
    rep(i, n) {
        int k; cin >> k;
        rep(j, k) {
            int c; cin >> c;
            G[i].push_back({0, c});
        }
    }
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op==0) {
            int v, w; cin >> v >> w;

        } else if(op==1) {
            int u; cin >> u;

        }
    }

    return 0;
}