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
using vc=vt<int>;
using vv=vvt<int>;
using vvv=vvvt<int>;
using pi=pair<int,int>;
template<class T>istream& operator>>(istream& i,vt<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vt<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vt<vt<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
const int INF=1e9;
//const ll INF=1e18;
#include <atcoder/dsu>
using namespace atcoder;
//(x1, y1)  (x2, y1)
//(x1, y2)  (x2, y2)
struct Rect {
    ll x1, x2, y1, y2;
    ll area() { return (x2-x1)*(y2-y1); }
};
bool adjacent(Rect r1, Rect r2) {
    if(r1.x1==r2.x2 && max(r1.y1, r2.y1)<min(r1.y2, r2.y2)) return true;
    if(r1.x2==r2.x1 && max(r1.y1, r2.y1)<min(r1.y2, r2.y2)) return true;
    if(r1.y1==r2.y2 && max(r1.x1, r2.x1)<min(r1.x2, r2.x2)) return true;
    if(r1.y2==r2.y1 && max(r1.x1, r2.x1)<min(r1.x2, r2.x2)) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; ll x, y; cin >> n >> x >> y;
    vt<Rect> rect;
    rect.pb({0, x, 0, y});
    rep(i, n) {
        char c; ll a, b; cin >> c >> a >> b;
        vt<Rect> next;
        for(auto r:rect) {
            if(c=='X') {
                if(r.x1<a && a<r.x2) {
                    next.pb({r.x1, a, r.y1-b, r.y2-b});
                    next.pb({a, r.x2, r.y1+b, r.y2+b});
                } else if(a<=r.x1) next.pb({r.x1, r.x2, r.y1+b, r.y2+b});
                else next.pb({r.x1, r.x2, r.y1-b, r.y2-b});
            } else if(c=='Y') {
                if(r.y1<a && a<r.y2) {
                    next.pb({r.x1-b, r.x2-b, r.y1, a});
                    next.pb({r.x1+b, r.x2+b, a, r.y2});
                } else if(a<=r.y1) next.pb({r.x1+b, r.x2+b, r.y1, r.y2});
                else next.pb({r.x1-b, r.x2-b, r.y1, r.y2});
            }
        }
        rect=next;
    }
    int m=rect.size();
    dsu uf(m);
    rep(i, m) rep(j, i) if(adjacent(rect[i], rect[j])) {
        uf.merge(i, j);
    }
    map<int, ll> component;
    rep(i, m) {
        int root=uf.leader(i);
        component[root]+=rect[i].area();
    }
    vt<ll> size;
    for(auto p:component) size.pb(p.second);
    sort(all(size));
    cout << size.size() << endl;
    cout << size;

    return 0;
}