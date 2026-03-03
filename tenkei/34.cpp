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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;
    int unique=0;
    int ans=-1;
    int r=0;
    rep(l, n) {
        while(r<n) {
            //uniqueが変わらないんだったらunique==kでもまだ追加できる
            if(mp[a[r]]==0) {
                if(unique==k) break;
                unique++;
            }
            mp[a[r]]++;
            r++;
        }
        ans=max(ans, r-l);
        if(mp[a[l]]==1) unique--;
        mp[a[l]]--;
    }
    cout << ans << endl;

    return 0;
}