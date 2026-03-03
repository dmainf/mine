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
    int n, m;
    cin >> n >> m;
    vector<pi> edges(m);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i]={u, v};
    }
    int ans=INF;
    rep(x, 1<<n) {
        int cnt=0;
        rep(i, m) {
            auto [u, v]=edges[i];
            int color_u=(x>>u)&1;
            int color_v=(x>>v)&1;
            if(color_u==color_v) cnt++;
        }
        ans=min(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}