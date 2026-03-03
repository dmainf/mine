#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define irep(i,n) for(int i=0;i<=(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define YN {YES}else{NO}
#define dame cout<<-1<<endl
using ll=long long;
template<class T>using vt=vector<T>;
template<class T>using vvt=vt<vt<T>>;
template<class T>using vvvt=vvt<vt<T>>;
using vc=vt<ll>;
using vv=vvt<int>;
using vvv=vvvt<int>;
using pi=pair<int,int>;
template<class T>istream& operator>>(istream& i,vt<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vt<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vt<vt<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
//const int INF=1e9;
//const ll INF=1e18;
#include <atcoder/lazysegtree>
using namespace atcoder;
using S=long long;
using F=long long;
const S INF=1LL<<60;
S op(S a, S b){ return max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vc a(n); cin >> a;
    ll cur=0;
    rep(i, n-1) cur+=abs(a[i]-a[i+1]);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(n);
    rep(i,n) seg.set(i,a[i]);
    while(q--) {
        int l, r, v; cin >> l >> r >> v;
        l--;
        if(0<l) cur-=abs(seg.get(l-1)-seg.get(l));
        if(r<n) cur-=abs(seg.get(r-1)-seg.get(r));
        seg.apply(l,r,v);
        if(0<l) cur+=abs(seg.get(l-1)-seg.get(l));
        if(r<n) cur+=abs(seg.get(r-1)-seg.get(r));
        cout << cur << endl;
    }

    return 0;
}