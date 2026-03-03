#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
using ll=long long;
#include <atcoder/modint>
using namespace atcoder;
using mint=modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> dice(n, vector<ll>(6));
    rep(i, n) rep(j, 6) cin >> dice[i][j];
    //a1 a2
    //b1 b2
    //c1 c2
    //a1b1(c*)+a1b2(c*)+a2b1(c*)+a2b2(c*)
    //a1(b*)(c*)+a2(b*)(c*)
    //(a*)(b*)(c*)
    mint ans=1;
    rep(i, n) {
        ll tmp=0;
        rep(j, 6) tmp+=dice[i][j];
        ans*=tmp;
    }
    cout << ans.val() << endl;

    return 0;
}