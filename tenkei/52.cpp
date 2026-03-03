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
#include <atcoder/modint>
using namespace atcoder;
using mint=modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  n; cin >> n;
    vv a(n,vc(6)); cin >> a;
    vc sum(n);
    rep(i, n) rep(j, 6) sum[i]+=a[i][j];
    mint ans=1;
    rep(i, n) ans*=sum[i];
    cout << ans.val() << endl;
    return 0;
}