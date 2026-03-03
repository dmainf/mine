#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
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
template<class T>using vc=vector<T>;
template<class T>using vvc=vc<vc<T>>;
template<class T>using vvvc=vvc<vc<T>>;
using vi=vc<ll>;
using vv=vvc<ll>;
using vvv=vvvc<ll>;
using pi=pair<ll,ll>;
template<class T>istream& operator>>(istream& i,vc<T>& v){
rep(j, size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vc<T>& v){
rep(j, size(v)){if(j)o<<" "; o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vc<vc<T>>& v){
rep(j, size(v)){rep(k, size(v[j])){if(k)o<<" "; o<<v[j][k];}o<<endl;}return o;}
//const ll INF=1e9;
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, Q; cin >> n >> Q;
    vc<pi> p(n);
    ll mn_x=INF, mx_x=-INF;
    ll mn_y=INF, mx_y=-INF;
    rep(i, n) {
        int x, y; cin >> x >> y;
        ll X=x-y;
        ll Y=x+y;
        mn_x=min(mn_x, X);
        mx_x=max(mx_x, X);
        mn_y=min(mn_y, Y);
        mx_y=max(mx_y, Y);
        p[i]={X, Y};
    }
    vi ans;
    while(Q--) {
        ll q; cin >> q;
        q--;
        auto [x, y]=p[q];
        ll a=abs(mn_x-x);
        ll b=abs(mx_x-x);
        ll c=abs(mn_y-y);
        ll d=abs(mx_y-y);
        ans.pb(max({a, b, c, d}));
    }
    cout << ans;

    return 0;
}