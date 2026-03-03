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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, y; cin >> n >> x >> y;
    vt<ll> a(n);
    cin >> a;
    //ai = xi+yi
    //w = x*xi + y*yi
    //yi = (w-x*ai)/(y-x)
    //yi-y0 = (w-x*ai)/(y-x) - (w - x*a0)/(y-x)
    //      = x*(a0-ai)/(y-x)
    ll d=y-x;
    rep(i, n) {
        if((x*(a[0]-a[i]))%d!=0) {
            dame;
            return 0;
        }
    }
    ll mn=0, mx=a[0];
    rep(i, n) {
        ll diff=x*(a[0]-a[i])/d;
        ll kagen=-diff;
        ll jougen=a[i]-diff;
        mn=max(mn, kagen);
        mx=min(mx, jougen);
    }
    if(mn>mx) {
        dame;
        return 0;
    }
    ll ans=0;
    rep(i, n) {
        ll diff=x*(a[0]-a[i])/d;
        ans+=mx+diff;
    }
    cout << ans << endl;

    return 0;
}
