#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define irep(i,n) for(ll i=0;i<=(n);i++)
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
using vv=vvt<ll>;
using vvv=vvvt<ll>;
using pi=pair<ll,ll>;
template<class T>istream& operator>>(istream& i,vt<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vt<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vt<vt<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
//const ll INF=1e9;
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) {
        ll n, w; cin >> n >> w;
        vc c(n); cin >> c;
        ll W=2*w;
        vc diff(W+1, 0);
        rep(i, n) {
            ll idx=i+1;
            ll s=(W-(idx%W))%W;
            diff[s]+=c[i];
            if(s+w<W) diff[s+w]-=c[i];
            else {
                diff[W]-=c[i];
                diff[0]+=c[i];
                diff[s+w-W]-=c[i];
            }
        }
        rep(i, W) diff[i+1]+=diff[i];
        ll ans=INF;
        rep(i, W) ans=min(ans, diff[i]);
        cout << ans << endl;
    }

    return 0;
}