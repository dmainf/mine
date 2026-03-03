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
    while(t--) {
        int n, c; cin >> n >> c;
        c--;
        vt<string> s(n); cin >> s;
        vc bound_wall(n, -1);
        rep(j, n) for(int i=n-1; i>=0; i--) if(s[i][j]=='#') {
            bound_wall[j]=i;
            break;
        }
        vc dp(n, 0);
        //0 nope
        //1 access, left
        //2 access, clean
        dp[c]=2;
        for(int i=n-1; i>=1; i--) {
            int nrow=i-1;
            vc ndp(n, 0);
            rep(j, n) {
                for(int v=-1; v<=1; v++) {
                    int nj=j+v;
                    if(nj<0||nj>=n) continue;
                    if(dp[j]==0) continue;
                    char ncell=s[nrow][nj];
                    int cur=dp[j];
                    int next=0;
                    if(ncell=='.') {
                        bool flag=false;
                        if(v==0 && cur==2) flag=true;
                        else if(bound_wall[nj]<nrow+1) flag=true;
                        next=flag ? 2:1;
                    } else {
                        if(v==0 && cur==2) next=2;
                        else next=0;
                    }
                    if(ndp[nj]<next) ndp[nj]=next;
                }
            }
            dp=ndp;
        }
        string ans="";
        rep(j, n) ans+=(0<dp[j] ? '1':'0');
        cout << ans << endl;
    }

    return 0;
}