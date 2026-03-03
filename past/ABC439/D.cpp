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
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    vc a(n); cin >> a;
    map<ll, ll> cnt;
    rep(i, n) cnt[a[i]]++;
    ll ans=0;
    map<ll, ll> cnt_left;
    rep(j, n) {
        if(a[j]%5==0) {
            ll base=a[j]/5;
            ans+=cnt_left[base*3]*cnt_left[base*7];
            ll right3=cnt[base*3]-cnt_left[base*3];
            ll right7=cnt[base*7]-cnt_left[base*7];
            ans+=right3*right7;
        }
        cnt_left[a[j]]++;
    }
    cout << ans << endl;

    return 0;
}