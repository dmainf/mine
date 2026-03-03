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
    int n, now;
    cin >> n >> now;
    vector<int> door(n);
    rep(i, n) cin >> door[i];
    int open=0;
    rep(i, n) if(door[i]==0) open++;
    if(open==0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> seq(n+1, 0);
    rep(i, n) {
        if(door[i]==1) seq[i+1]=seq[i]+1;
        else seq[i+1]=seq[i];
    }
    int left=INT_MAX, right=INT_MIN;
    rep(i, n) if(door[i]==0) {
        left=min(left, seq[i]);
        right=max(right, seq[i]);
    }
    ll extra=right-left;
    if(seq[now]<left) extra+=left-seq[now];
    if(seq[now]>right) extra+=seq[now]-right;
    ll ans=(ll)open+2LL*extra;
    cout << ans << endl;

    return 0;
}