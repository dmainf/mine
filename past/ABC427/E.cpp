#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={-1,+1,+0,+0};
const int dj[]={+0,+0,-1,+1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ti, tj;
    vector<pi> ini_trush;
    rep(i, h) rep(j, w) if(s[i][j]=='T') {
        ti=i; tj=j;
    }
    rep(i, h) rep(j, w) if(s[i][j]=='#') {
        ini_trush.push_back({i, j});
    }
    map<vector<pi>, int> dist;
    queue<vector<pi>> que;
    que.push(ini_trush);
    dist[ini_trush]=0;
    while(!que.empty()) {
        vector<pi> trash=que.front();
        que.pop();
        if(trash.empty()) {
            cout << dist[trash] << endl;
            return 0;
        }
        int d=dist[trash];
        rep(v, 4) {
            vector<pi> n_trush;
            bool flag=false;
            for(auto [i, j]:trash) {
                int ni=i+di[v];
                int nj=j+dj[v];
                if(ni<0 || ni>=h) continue;
                if(nj<0 || nj>=w) continue;
                if(ni==ti && nj==tj) {
                    flag=true;
                    break;
                }
                n_trush.push_back({ni, nj});
            }
            if(flag) continue;
            sort(all(n_trush));
            if(!dist.count(n_trush)) {
                dist[n_trush]=d+1;
                que.push(n_trush);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}