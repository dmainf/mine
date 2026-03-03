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
    int  n; cin >> n;
    vector<vector<int>> G(n);
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    que.push(0);
    vector<int> color(n, -1);
    color[0]=0;
    while(!que.empty()) {
        int v=que.front();
        que.pop();
        for(int nv:G[v]) if(color[nv]==-1) {
            color[nv]=((color[v]==0) ? 1:0);
            que.push(nv);
        }
    }
    vector<int> black, white;
    rep(i, n) {
        if(color[i]==0) black.push_back(i+1);
        else white.push_back(i+1);
    }
    vector<int> ans;
    if((n/2)<=black.size()) ans=black;
    else ans=white;
    rep(i, n/2) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}