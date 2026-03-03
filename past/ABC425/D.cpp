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
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    queue<pi> que;
    rep(i, h) rep(j, w) if(s[i][j]=='#') {
        que.push({i, j});
        seen[i][j]=true;
    }
    while(!que.empty()) {
        int size=que.size();
        set<pi> st;
        rep(_, size) {
            auto [i, j]=que.front();
            que.pop();
            rep(v, 4) {
                int ni=i+di[v];
                int nj=j+dj[v];
                if(ni<0 || h<=ni) continue;
                if(nj<0 || w<=nj) continue;
                if(seen[ni][nj]) continue;
                int cnt=0;
                rep(vv, 4){
                    int nni=ni+di[vv];
                    int nnj=nj+dj[vv];
                    if(nni<0 || h<=nni) continue;
                    if(nnj<0 || w<=nnj) continue;
                    if(s[nni][nnj]=='#') cnt++;
                }
                if(cnt==1) st.insert({ni, nj});
            }
        }
        for(auto [ai, aj]:st) {
            s[ai][aj]='#';
            que.push({ai, aj});
        }
    }
    int ans=0;
    rep(i, h) rep(j, w) if(s[i][j]=='#') ans++;
    cout << ans << endl;

    return 0;
}