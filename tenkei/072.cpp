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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ans=-1;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    auto dfs=[&](auto dfs, vector<vector<bool>> seen, int i, int j, int si, int sj, int len) -> void {
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(ni<0 || h<=ni) continue;
            if(nj<0 || w<=nj) continue;
            if(s[ni][nj]=='#') continue;
            if(ni==si && nj==sj && 3<=len) ans=max(ans, len);
            if(!seen[ni][nj]) {
                seen[ni][nj]=true;
                dfs(dfs, seen, ni, nj, si, sj, len+1);
                seen[ni][nj]=false;
            }
        }
    };
    rep(si, h) rep(sj, w) if(s[si][sj]=='.') {
        vector<vector<bool>> seen(h, vector<bool>(w, false));
        seen[si][sj]=true;
        dfs(dfs, seen, si, sj, si, sj, 1);
    }
    cout << ans << endl;

    return 0;
}