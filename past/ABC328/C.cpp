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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pre(n+1, 0);
    rep(i, n) {
        if(s[i]==s[i-1]) pre[i+1]=pre[i]+1;
        else pre[i+1]=pre[i];
    }
    vector<int> ans;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        ans.push_back(pre[r]-pre[l]);
    }
    for(auto x:ans) cout << x << endl;

    return 0;
}