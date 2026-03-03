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
using vv=vvt<ll>;
using vvv=vvvt<ll>;
using pi=pair<ll,ll>;
template<class T>istream& operator>>(istream& i,vt<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vt<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vt<vt<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
const int INF=1e9;
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll  n, k, p; cin >> n >> k >> p;
    vc a(n); cin >> a;
    vc a1(a.begin(),a.begin()+n/2);
    vc a2(a.begin()+n/2,a.end());
    vv sum1(a1.size()+1), sum2(a2.size()+1);
    auto f=[&](vc a) -> vv {
        vv res(a.size()+1);
        rep(mask,(1<<a.size())){
            ll tmp=0;
            rep(bit,a.size()) if((mask>>bit)&1){
                tmp+=a[bit];
            }
            res[__builtin_popcount(mask)].pb(tmp);
        }
        return res;
    };
    sum1=f(a1);
    sum2=f(a2);
    for(auto &x:sum2) sort(all(x));
    ll ans=0;
    rep(i, sum1.size()){
        if(k-i<0 || sum2.size()<=k-i) continue;
        for(ll x:sum1[i]){
            ll it=upper_bound(all(sum2[k-i]),p-x)-sum2[k-i].begin();
            ans+=it;
        }
    }
    cout << ans << endl;

    return 0;
}