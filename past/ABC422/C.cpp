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
    ll t; cin >> t;
    vector<ll> ans;
    while(t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ans.push_back(min({a, c, (a+b+c)/3}));
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}