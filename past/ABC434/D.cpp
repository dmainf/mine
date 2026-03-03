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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    const int MAX_H=2005;
    const int MAX_W=2005;
    vv grid(MAX_H, vc(MAX_W, 0));
    vv one(MAX_H, vc(MAX_W, 0));
    vv S(MAX_H, vc(MAX_W, 0));
    vt<tuple<int,int,int,int>> clouds(n);
    rep(i, n) {
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        clouds[i]={u, d, l, r};
        grid[u][l]++;
        grid[u][r+1]--;
        grid[d+1][l]--;
        grid[d+1][r+1]++;
    }
    rep(i, MAX_H) rep(j, MAX_W-1) {
        grid[i][j+1]+=grid[i][j];
    }
    rep(j, MAX_W) rep(i, MAX_H-1) {
        grid[i+1][j]+=grid[i][j];
    }
    ll base=0;
    for(int i=1; i<=2000; i++) for(int j=1; j<=2000; j++) {
        if(grid[i][j]==0) base++;
        if(grid[i][j]==1) one[i][j]=1;
    }
    for(int i=1; i<=2000; i++) for(int j=1; j<=2000; j++) {
        S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+one[i][j];
    }
    rep(k, n) {
        auto [u, d, l, r]=clouds[k];
        int cnt1=S[d][r]-S[u-1][r]-S[d][l-1]+S[u-1][l-1];
        cout << base+cnt1 << endl;
    }

    return 0;
}