#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
//const int INF=1e9;
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i, n) dist[i][i]=0;
    rep(i, m) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t]=d;
    }
    rep(k, n) rep(i, n) rep(j, n) {
        if(dist[i][k]==INF || dist[k][j]==INF) continue;
        dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    rep(i, n) if(dist[i][i]<0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep(i, n) {
        rep(j, n) {
            if(j!=0) cout << " ";
            if(dist[i][j]==INF) {
                cout << "INF";
            } else {
                cout << dist[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}