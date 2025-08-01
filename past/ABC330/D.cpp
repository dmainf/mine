#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>; 
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<int> row(n, 0), col(n, 0);
    rep(i, n) rep(j, n) if(s[i][j]=='o') {
        row[i]++;
        col[j]++;
    }
    ll ans=0;
    rep(i, n) rep(j, n) if(s[i][j]=='o') {
        ans+=(row[i]-1)*(col[j]-1);
    }
    cout << ans << endl;

    return 0;
}