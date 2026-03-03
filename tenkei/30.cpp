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
    vector<int> num(n+1, 0);
    for(int i=2; i<=n; i++) {
        //if not prime, continue
        if(num[i]!=0) continue;
        for(int j=i; j<=n; j+=i) num[j]++;
    }
    int ans=0;
    for(int i=2; i<=n; i++) if(k<=num[i]) ans++;
    cout << ans << endl;

    return 0;
}