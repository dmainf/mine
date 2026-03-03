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
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vc a(n), b(n), c(n); cin >> a >> b >> c;
    vc pre_a(n+1, 0), pre_b(n+1, 0), pre_c(n+1, 0);
    rep(i, n) {
        pre_a[i+1]=pre_a[i]+a[i];
        pre_b[i+1]=pre_b[i]+b[i];
        pre_c[i+1]=pre_c[i]+c[i];
    }
    vc L(n+1), R(n+1);
    rep(i, n+1) {
        L[i]=pre_a[i]-pre_b[i];
        R[i]=(pre_c[n]-pre_c[i])-(pre_b[n]-pre_b[i]);
    }
    ll mx_L=L[1];
    ll ans=-INF;
    for(int i=2; i<n; i++) {
        mx_L=max(mx_L, L[i-1]);
        ans=max(ans, mx_L+R[i]+pre_b[n]);
    }
    cout << ans << endl;

    return 0;
}