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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int q; cin >> q;
    set<char> ss(all(s)), tt(all(t));
    while(q--) {
        string w; cin >> w;
        bool takahashi=true, aoki=true;
        bool nottakahashi=false, notaoki=false;
        for(char c:w) {
            if(!ss.count(c)) takahashi=false, nottakahashi=true;
            if(!tt.count(c)) aoki=false, notaoki=true;
        }
        if(takahashi && notaoki) cout << "Takahashi" << endl;
        else if(aoki && nottakahashi) cout << "Aoki" << endl;
        else cout << "Unknown" << endl;
    }
    return 0;
}