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
const int INF=1e9;
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> deg(n, 0);
    rep(i, m) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        deg[t]++;
    }
    queue<int> que;
    rep(i, n) if(deg[i]==0) que.push(i);
    vector<int> topo;
    while(!que.empty()) {
        int v=que.front();
        que.pop();
        for(int nv:G[v]) {
            deg[nv]--;
            if(deg[nv]==0) que.push(nv);
        }
        topo.push_back(v);
    }
    for(int x:topo) cout << x << endl;

    return 0;
}