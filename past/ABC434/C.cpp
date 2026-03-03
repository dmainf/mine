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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    vt<bool> ans;
    while(t--) {
        int n;
        ll h;
        cin >> n >> h;
        vt<ll> time(n), l(n), u(n);
        rep(i, n) cin >> time[i] >> l[i] >> u[i];
        ll min_h=h, max_h=h;
        bool flag=true;
        rep(i, n) {
            ll dt=(i==0) ? time[0]:(time[i]-time[i-1]);
            min_h=max(1LL, min_h-dt);
            max_h=max_h+dt;
            min_h=max(min_h, l[i]);
            max_h=min(max_h, u[i]);
            if (min_h>max_h) {
                flag=false;
                break;
            }
        }
        ans.pb(flag);
    }
    for(bool x:ans) if(x) YES; else NO;

    return 0;
}