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
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> score(102, 0);
    rep(i, n) score[p[i]]++;
    rep(i, 101) score[i+1]=score[i+1]+score[i];
    rep(i, n) cout << n+1-score[p[i]] << endl;

    return 0;
}