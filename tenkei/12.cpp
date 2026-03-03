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
#include <atcoder/dsu>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w; cin >> h >> w;
    int q; cin >> q;
    vector<vector<bool>> b(h, vector<bool>(w, false));
    dsu uf(h*w);
    vector<bool> ans;
    auto f=[&](int r, int c) -> int { return r*w+c; };
    while (q--) {
        int op; cin >> op;
        if(op==1) {
            int r, c; cin >> r >> c;
            r--; c--;
            b[r][c]=true;
            rep(v, 4) {
                int nr=r+di[v];
                int nc=c+dj[v];
                if(nr<0 || h<=nr) continue;
                if(nc<0 || w<=nc) continue;
                if(b[nr][nc]) uf.merge(f(r, c), f(nr, nc));
            }
        } else if(op==2) {
            int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--;
            ans.push_back((b[ra][ca] && b[rb][cb]) && (uf.same(f(ra, ca), f(rb, cb))));
        }
    }
    for(bool x:ans) {
        if(x) YES;
        else NO;
    }

    return 0;
};