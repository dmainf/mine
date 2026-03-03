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
    int n, s;
    cin >> n >> s;
    vector<pi> box(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        box[i]={a, b};
    }
    vector<vector<bool>> dp(n+1, vector<bool>(s+1, false));
    dp[0][0]=true;
    rep(i, n) {
        int a=box[i].first, b=box[i].second;
        rep(j, s+1) {
            if(j+a<=s && dp[i][j]) dp[i+1][j+a]=true;
            if(j+b<=s && dp[i][j]) dp[i+1][j+b]=true;
        }
    }
    if(!dp[n][s]) {
        cout << "Impossible" << endl;
        return 0;
    }
    string ans="";
    int now=s;
    for(int i=n; i>=1; i--) {
        int a=box[i-1].first, b=box[i-1].second;
        if(0<=now-a && dp[i-1][now-a]) { now-=a; ans+='A'; }
        else { now-=b; ans+='B'; }
    }
    reverse(all(ans));
    cout << ans << endl;

    return 0;
}