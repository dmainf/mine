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
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
bool out_grid(int i,int j,int h,int w){
    return (i<0||h<=i||j<0||w<=j);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w; cin >> h >> w;
    int si, sj; cin >> si >> sj;
    si--; sj--;
    int gi, gj; cin >> gi >> gj;
    gi--; gj--;
    vt<string> s(h);
    rep(i, h) cin >> s[i];
    vvv dist(h, vv(w, vc(4, INF)));
    rep(v, 4) dist[si][sj][v]=0;
    deque<tuple<int,int,int>> dq;
    rep(v, 4) dq.pb({si, sj, v});
    while(!dq.empty()) {
        auto [i, j, v]=dq.front();
        dq.popf();
        rep(nv, 4) {
            int ni=i+di[nv];
            int nj=j+dj[nv];
            if(out_grid(ni, nj, h, w)) continue;
            if(s[ni][nj]=='#') continue;
            int cost=(nv==v) ? 0:1;
            if(dist[i][j][v]+cost<dist[ni][nj][nv]) {
                dist[ni][nj][nv]=dist[i][j][v]+cost;
                if(cost==0) dq.pf({ni, nj, nv});
                else dq.pb({ni, nj, nv});
            }
        }
    }
    cout << *min_element(all(dist[gi][gj])) << endl;

    return 0;
}