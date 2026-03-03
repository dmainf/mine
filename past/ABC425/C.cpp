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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> sum(2*n+1, 0);
    rep(i, 2*n) sum[i+1]=sum[i]+a[i%n];
    int shift=0;
    vector<ll> ans;
    while(q--) {
        int op; cin >> op;
        if(op==1) {
            int c; cin >> c;
            shift=(shift+c)%n;
        }
        if(op==2) {
            int l, r; cin >> l >> r;
            l--; r--;
            int start=(l+shift)%n;
            int end=(r+shift)%n;
            ll tmp=0;
            if(start<=end) tmp=sum[end+1]-sum[start];
            else tmp=sum[n]-sum[start]+sum[end+1];
            ans.push_back(tmp);
        }
    }
    for(ll x:ans) cout << x << endl;

    return 0;
}