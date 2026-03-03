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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> diff(n, 0);
    rep(i, n-1) diff[i+1]=a[i+1]-a[i];
    ll now=0;
    rep(i, n) now+=abs(diff[i]);
    vector<ll> ans;
    while(q--) {
        int l ,r, v;
        cin >> l >> r >> v;
        l--; r--;
        if(0<l) {
            now-=abs(diff[l]);
            diff[l]+=v;
            now+=abs(diff[l]);
        }
        if(r+1<n) {
            now-=abs(diff[r+1]);
            diff[r+1]-=v;
            now+=abs(diff[r+1]);
        }
        ans.push_back(now);
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}