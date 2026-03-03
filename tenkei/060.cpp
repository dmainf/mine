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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> f(n), b(n), dp(n);
    int cnt=0;
    rep(i, n) {
        int it=lower_bound(dp.begin(), dp.begin()+cnt, a[i])-dp.begin();
        dp[it]=a[i];
        f[i]=it+1;
        if(it==cnt) cnt++;
    }
    cnt=0;
    fill(all(dp), 0);
    for(int i=n-1; i>=0; i--) {
        int it=lower_bound(dp.begin(), dp.begin()+cnt, a[i])-dp.begin();
        dp[it]=a[i];
        b[i]=it+1;
        if(it==cnt) cnt++;
    }
    //1 2 3 3 2 1
    //1 2 3 3 2 1
    //1 2 3 3 2 1
    int ans=-1;
    rep(i, n) ans=max(ans, f[i]+b[i]);
    cout << ans-1 << endl;

    return 0;
}