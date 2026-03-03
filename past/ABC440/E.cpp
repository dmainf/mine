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
const ll INF=1e9;
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x; cin >> n >> k >> x;
    vc a(n); cin >> a;
    sort(rall(a));
    set<vc> seen;
    priority_queue<pair<ll, vc>> pq;
    vc start(n, 0); start[0]=k;
    pq.push({k*a[0], start});
    seen.insert(start);
    while(!pq.empty()) {
        auto [val, state]=pq.top(); pq.pop();
        cout << val << endl; x--;
        if(x==0) break;
        rep(i, n-1) if(state[i]>0) {
            vc nstate=state;
            nstate[i]--;
            nstate[i+1]++;
            if(seen.count(nstate)) continue;
            ll nval=val-a[i]+a[i+1];
            pq.push({nval, nstate});
            seen.insert(nstate);
        }
    }

    return 0;
}