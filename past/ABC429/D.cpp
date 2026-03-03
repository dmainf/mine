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
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, c;
    cin >> n >> m >> c;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vector<pi> b;
    rep(i, n) {
        if(!b.empty() && b.back().first==a[i]) b.back().second++;
        else b.push_back({a[i], 1});
    }
    int K=(int)b.size();
    vector<pi> p=b;
    for(auto [x, cnt]:b) p.push_back({x+m, cnt});
    ll ans=0;
    ll sum=0;
    int r=0;
    rep(l, K) {
        while(r<(int)p.size() && sum<c){
            sum+=p[r].second;
            r++;
        }
        if(sum<c) break;
        ll pre;
        if(l==0) pre=b.back().first-m;
        else pre=b[l-1].first;
        ll len=b[l].first-pre;
        ans+=len*sum;
        sum-=p[l].second;
    }
    cout << ans << endl;

    return 0;
}