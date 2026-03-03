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
    int n, p, q;
    cin >> n >> p >> q;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    ll ans=0;
    rep(a, n) rep(b, a) rep(c, b) rep(d, c) rep(e, d) {
        if(x[a]%p *x[b]%p *x[c]%p *x[d]%p *x[e]%p==q) ans++;
    }
    cout << ans << endl;

    return 0;
}