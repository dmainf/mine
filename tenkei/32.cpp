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
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    int m; cin >> m;
    set<pi> bad;
    rep(i, m) {
        int x, y; cin >> x >> y;
        x--; y--;
        bad.insert({x, y});
        bad.insert({y, x});
    }
    vector<int> order;
    rep(i, n) order.push_back(i);
    int ans=INF;
    do {
        bool flag=false;
        rep(i, n-1) if(bad.count({order[i], order[i+1]})) {
            flag=true;
        }
        if(flag) continue;
        int tmp=0;
        rep(i, n) tmp+=a[order[i]][i];
        ans=min(ans, tmp);
    } while(next_permutation(all(order)));
    if(ans==INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}