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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> p(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> p[i][j];
    int ans=0;
    rep(x, 1<<h) {
        map<int, int> mp;
        rep(j, w) {
            int val=-1;
            bool flag=true;
            rep(i, h) if((x>>i)&1) {
                if(val==-1) val=p[i][j];
                else if(val!=p[i][j]) {
                    flag=false;
                    break;
                }
            }
            if(flag && val!=-1) mp[val]++;
        }
        int row=__builtin_popcount(x);
        for(auto [x, col]:mp) ans=max(ans, row*col);
    }
    cout << ans << endl;

    return 0;
}