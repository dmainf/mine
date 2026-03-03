#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<ll,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p, k;
    cin >> n >> p >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n)rep(j, n) cin >> a[i][j];
    auto f=[&](ll x) -> ll {
        vector<vector<ll>> dist(n, vector<ll>(n, 1e18));
        rep(i, n) rep(j, n) {
            if(a[i][j]==-1) dist[i][j]=x;
            else dist[i][j]=a[i][j];
        }
        rep(z, n) rep(i, n) rep(j, n) {
            dist[i][j]=min(dist[i][j], dist[i][z]+dist[z][j]);
        }
        ll cnt=0;
        rep(i, n) for(int j=i+1; j<n; j++) {
            if(dist[i][j]<=p) cnt++;
        }
        return cnt;
    };
    //xが増えるほどkが減る
    auto g=[&](ll val) {
        ll l=1, r=p+1;
        while(l<=r) {
            ll mid=(l+r)/2;
            if(val<=f(mid)) l=mid+1;
            else r=mid-1;
        }
        return l;
    };
    if(f(p+1)==k) {
        cout << "Infinity" << endl;
        return 0;
    }
    ll lower=g(k+1);
    ll upper=g(k);
    cout << upper-lower << endl;

    return 0;
}