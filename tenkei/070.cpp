#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    sort(all(x));
    sort(all(y));
    ll powerx=x[n/2], powery=y[n/2];
    ll ans=0;
    rep(i, n) {
        ans+=abs(x[i]-powerx);
        ans+=abs(y[i]-powery);
    }
    cout << ans << endl;

    return 0;
}