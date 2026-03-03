#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=unsigned long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
#include <atcoder/modint>
using namespace atcoder;
using mint=modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    vector<ll> degit(20, 0);
    degit[0]=1;
    for(int i=1; i<20; i++) degit[i]=degit[i-1]*10;
    mint ans=0;
    for(int i=1; i<20; i++) {
        ll left=max(l, degit[i-1]);
        ll right=min(r, degit[i]-1);
        if(left>right) continue;
        mint sum=(mint)(left+right)*(mint)(right-left+1)/2;
        ans+=mint(i)*sum;
    }
    cout << ans.val() << endl;

    return 0;
}