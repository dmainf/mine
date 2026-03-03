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
#include <atcoder/dsu>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<ll> pc(n+1, 1), nxt(n+2, 0);
    rep(i, n+2) nxt[i]=i;
    dsu uf(n+2);
    vector<int> ans;
    auto find_next=[&](auto self,int x) ->int {
        if(nxt[x]==x) return x;
        return nxt[x]=self(self,nxt[x]);
    };
    while(q--) {
        int x, y;
        cin >> x >> y;
        ll tmp=0;
        int v=find_next(find_next, 1);
        while(v<=x) {
            if(v==y) {
                v=find_next(find_next,v+1);
                continue;
            }
            tmp+=pc[v];
            pc[y]+=pc[v];
            pc[v]=0;
            uf.merge(v, v+1);
            nxt[v]=find_next(find_next,v+1);
            v=nxt[v];
        }
        ans.push_back(tmp);
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}