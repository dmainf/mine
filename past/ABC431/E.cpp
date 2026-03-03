#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+0,+1,-1,+0};
const int dj[]={+1,+0,+0,-1};
//               →  ↓  ↑  ←
const int INF=1e9;
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    auto reflect=[&](int v, char type) -> int {
        int nv;
        if(type=='A') nv=v;
        if(type=='B') {
            if(v==0) nv=1;
            if(v==1) nv=0;
            if(v==2) nv=3;
            if(v==3) nv=2;
        }
        if(type=='C') {
            if(v==0) nv=2;
            if(v==1) nv=3;
            if(v==2) nv=0;
            if(v==3) nv=1;
        }
        return nv;
    };
    vector<int> ans;
    while(t--) {
        int h, w; cin >> h >> w;
        vector<string> s(h);
        rep(i, h) cin >> s[i];
        deque<tuple<int, int, int>> dq;
        dq.push_back({0, 0, 0});
        vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(4, INF)));
        dist[0][0][0]=0;
        int best=INF;
        while(!dq.empty()) {
            auto [i, j, dir]=dq.front();
            dq.pop_front();
            int wei=dist[i][j][dir];
            if(wei==INF) continue;
            for(char c='A'; c<='C'; c++) {
                int ndir=reflect(dir, c);
                int ni=i+di[ndir];
                int nj=j+dj[ndir];
                int cost=(c==s[i][j]) ? 0:1;
                if(ni<0 || ni>=h || nj<0 || nj>=w) {
                    if(i==h-1 && j==w-1 && ndir==0) best=min(best, wei+cost);
                    continue;
                }
                if(wei+cost<dist[ni][nj][ndir]) {
                    dist[ni][nj][ndir]=wei+cost;
                    if(cost==0) dq.push_front({ni, nj, ndir});
                    else dq.push_back({ni, nj, ndir});
                }
            }
        }
        ans.push_back(best);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}