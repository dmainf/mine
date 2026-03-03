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
    int n, s; cin >> n >> s;
    vc a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vvt<bool> dp(n+1, vt<bool>(s+1, 0));
    dp[0][0] = true;
    rep(i, n) rep(j, s+1) {
        if(dp[i][j]) {
            if(j+a[i]<=s) dp[i+1][j+a[i]]=true;
            if(j+b[i]<=s) dp[i+1][j+b[i]]=true;
        }
    }
    if(!dp[n][s]) {
        cout << "Impossible" << endl;
        return 0;
    }
    string t="";
    int now=s;
    for(int i=n-1; i>=0; i--) {
        if(0<=now-a[i] && dp[i][now-a[i]]) {
            now-=a[i];
            t+='A';
        }
        else {
            now-=b[i];
            t+='B';
        }
    }
    reverse(all(t));
    cout << t << endl;
    return 0;
}