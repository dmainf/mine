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
#include <atcoder/modint>
using namespace atcoder;
using mint=modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l;
    cin >> n >> l;
    vector<mint> dp(n+1, 0);
    dp[0]=1;
    rep(i, n+1) {
        if(i+1<=n) dp[i+1]+=dp[i];
        if(i+l<=n) dp[i+l]+=dp[i];
    }
    cout << dp[n].val() << endl;

    return 0;
}