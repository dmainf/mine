#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,ll>;
const ll di[]={+1,-1,+0,+0};
const ll dj[]={+0,+0,+1,-1};
const ll INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> cor;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        cor.push_back(b);
        cor.push_back(a-b);
    }
    sort(rall(cor));
    ll ans=0;
    rep(i, k) ans+=cor[i];
    cout << ans << endl;

    return 0;
}