#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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
const ll INF=1e18;
ll op_max(ll a, ll b) { return max(a, b); }
ll e_max() { return -INF; }
ll op_min(ll a, ll b) { return min(a, b); }
ll e_min() { return INF; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vt<ll> X(n), Y(n);
    rep(i, n) cin >> X[i] >> Y[i];
    auto to_cheby_x = [&](ll x, ll y) { return x-y; };
    auto to_cheby_y = [&](ll x, ll y) { return x+y; };
    vc tree_x(n), tree_y(n);
    rep(i, n) {
        tree_x[i]=to_cheby_x(X[i], Y[i]);
        tree_y[i]=to_cheby_y(X[i], Y[i]);
    }
    segtree<ll, op_max, e_max> seg_x_max(tree_x);
    segtree<ll, op_min, e_min> seg_x_min(tree_x);
    segtree<ll, op_max, e_max> seg_y_max(tree_y);
    segtree<ll, op_min, e_min> seg_y_min(tree_y);
    while(q--) {
        int op; cin >> op;
        if(op==1) {
            int i; ll x, y; cin >> i >> x >> y;
            i--;
            X[i]=x; Y[i]=y;
            ll cx=to_cheby_x(x, y);
            ll cy=to_cheby_y(x, y);
            seg_x_max.set(i, cx);
            seg_x_min.set(i, cx);
            seg_y_max.set(i, cy);
            seg_y_min.set(i, cy);
        } else if(op==2) {
            int l, r; ll x, y; cin >> l >> r >> x >> y;
            l--;
            ll cx=to_cheby_x(x, y);
            ll cy=to_cheby_y(x, y);

            ll max_x=seg_x_max.prod(l, r);
            ll min_x=seg_x_min.prod(l, r);
            ll max_y=seg_y_max.prod(l, r);
            ll min_y=seg_y_min.prod(l, r);

            ll dist_x=max(abs(max_x-cx), abs(min_x-cx));
            ll dist_y=max(abs(max_y-cy), abs(min_y-cy));

            cout << max(dist_x, dist_y) << endl;
        }
    }

    return 0;
}
