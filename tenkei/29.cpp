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
//const int INF=1e9;
//const ll INF=1e18;
#include <atcoder/lazysegtree>
using namespace atcoder;
using S=long long;
using F=long long;
const S INF=1LL<<60;
const F ID=1LL<<60;
S op(S a, S b){ return max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return (f==ID ? x:f); }
F composition(F f, F g){ return (f==ID ? g:f); }
F id(){ return ID; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, n; cin >> w >> n;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(w+1);
    vector<int> brick(n);
    rep(i, n) {
        int l, r; cin >> l >> r;
        int highest=seg.prod(l, r+1);
        brick[i]=highest+1;
        seg.apply(l, r+1, brick[i]);
    }
    rep(i, n) cout << brick[i] << endl;

    return 0;
}