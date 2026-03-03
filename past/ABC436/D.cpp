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
    vt<string> s(h);
    rep(i, h) cin >> s[i];
    map<char, vt<pi>> mp;
    rep(i, h) rep(j, w) if('a'<=s[i][j] && s[i][j]<='z') {
        mp[s[i][j]].pb({i, j});
    }
    priority_queue<tuple<int,int,int>, vt<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, 0, 0});
    vv dist(h, vc(w, INF));
    dist[0][0]=0;
    vt<bool> used_char(26, false);
    while(!pq.empty()) {
        auto [d, i, j]=pq.top(); pq.pop();
        if(dist[i][j]<d) continue;
        rep(v, 4) {
            int ni=i+di[v];
            int nj=j+dj[v];
            if(out_grid(ni, nj, h, w)) continue;
            if(s[ni][nj]=='#') continue;
            if(dist[ni][nj]>d+1) {
                dist[ni][nj]=d+1;
                pq.push({d+1, ni, nj});
            }
        }
        if('a'<=s[i][j] && s[i][j]<='z') {
            int char_idx=s[i][j]-'a';
            if(!used_char[char_idx]) {
                used_char[char_idx]=true;
                for(auto [ni, nj]:mp[s[i][j]]) {
                    if(dist[ni][nj]>d+1) {
                        dist[ni][nj]=d+1;
                        pq.push({d+1, ni, nj});
                    }
                }
            }
        }
    }
    if(dist[h-1][w-1]==INF) dame;
    else cout << dist[h-1][w-1] << endl;

    return 0;
}