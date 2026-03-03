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
template<class T>using vc=vector<T>;
template<class T>using vvc=vc<vc<T>>;
template<class T>using vvvc=vvc<vc<T>>;
using vi=vc<int>;
using vv=vvc<int>;
using vvv=vvvc<int>;
using pi=pair<int,int>;
template<class T>istream& operator>>(istream& i,vc<T>& v){
rep(j,size(v))i>>v[j];return i;}
template<class T>ostream& operator<<(ostream& o,const vc<T>& v){
rep(j,size(v)){if(j)o<<" ";o<<v[j];}o<<endl;return o;}
template<class T>ostream& operator<<(ostream& o,const vc<vc<T>>& v){
rep(j,size(v)){rep(k,size(v[j])){if(k)o<<" ";o<<v[j][k];}o<<endl;}return o;}
//const int INF=1e9;
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b; cin >> a >> b;
    ll d=gcd(a, b);
    if(a/d>INF/b) cout << "Large" << endl;
    else cout << a/d*b << endl;

    return 0;
}