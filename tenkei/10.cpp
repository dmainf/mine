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
//const int INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> score(2, vector<int>(n, 0));
    rep(i, n) {
        int c, p; cin >> c >> p;
        c--;
        score[c][i]=p;
    }
    vector<vector<int>> prefix(2, vector<int>(n+1, 0));
    rep(i, n) rep(c, 2) {
        prefix[c][i+1]=score[c][i]+prefix[c][i];
    }
    int q; cin >> q;
    vector<pi> ans;
    while(q--) {
        int l, r; cin >> l >> r;
        int tmp1=prefix[0][r]-prefix[0][l-1];
        int tmp2=prefix[1][r]-prefix[1][l-1];
        ans.push_back({tmp1, tmp2});
    }
    for(auto [x, y]:ans) cout << x << " " << y << endl;

    return 0;
}