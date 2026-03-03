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
#include <atcoder/segtree>
using namespace atcoder;
int op(int a, int b) { return a+b; }
int e() { return 0; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vc p(n); cin >> p;
    vt<mint> pow2(n+1);
    vt<mint> inv_pow2(n+1);
    pow2[0]=1;
    inv_pow2[0]=1;
    mint inv2=mint(1)/2;
    rep(i, n) {
        pow2[i+1]=pow2[i]*2;
        inv_pow2[i+1]=inv_pow2[i]*inv2;
    }
    segtree<int, op, e> segL(n+1);
    vc L(n);
    rep(i, n) {
        L[]
    }

    return 0;
}