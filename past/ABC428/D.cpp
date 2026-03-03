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
ll floor_sqrt(ll x) {
    if (x < 0) return -1;
    long double xf = (long double)x;
    ll r = (ll)floor(sqrtl(xf));
    while ((ll)(r+1)*(r+1) <= x) ++r;
    while ((ll)r*r > x) --r;
    return r;
}

ll ceil_sqrt(ll x) {
    ll f = floor_sqrt(x);
    if ((ll)f*f == x) return f;
    return f + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    vector<int> ans;
    vector<ll> pow10(16, 1);
    for(int i=1; i<=15; i++) pow10[i]=pow10[i-1]*10;
    while(t--) {
        ll c, d;
        cin >> c >> d;
        ll tmp=0;
        for(int k=1; k<=11; k++) {
            // 10^{k-1} <= c+x <= 10^k - 1
            // x in [10^{k-1}-c, 10^k -1 - c]
            ll ten_k_1=pow10[k-1];
            ll ten_k=pow10[k];
            ll low_x=max(1LL, ten_k_1-c);
            ll high_x=min(d, ten_k-1-c);
            if(low_x>high_x) continue;
            // base = c*10^k + c = c*(10^k + 1)
            ll base=c*(pow10[k])+c;
            ll L=base+low_x;
            ll R=base+high_x;
            if(L>R) continue;
            ll n_min=ceil_sqrt(L);
            ll n_max=floor_sqrt(R);
            if(n_max>=n_min) tmp+=(n_max-n_min+1);
        }
        ans.push_back(tmp);
    }
    for(int x:ans) cout << x << endl;

    return 0;
}