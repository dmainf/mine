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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vc u(m), v(m);
    rep(i, m) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
    }
    vc wei(m+1);
    wei[0]=2;
    for(int i=1; i<=m; i++) wei[i]=(wei[i-1]*2)%998244353;
    dsu uf(n);
    int ans=0;
    int comp=n;
    for(int i=m-1; i>=0; i--) {
        int root_u=uf.leader(u[i]), root_v=uf.leader(v[i]);
        if(root_u!=root_v) {
            if(comp>2) {
                uf.merge(u[i], v[i]);
                comp--;
            } else {
                ans=(ans+wei[i])%998244353;
            }
        }
    }
    cout << ans << endl;

    return 0;
}