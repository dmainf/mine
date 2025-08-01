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
    int n, m;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    vector<int> c;
    set_difference(all(a), all(b), back_inserter(c));
    for(int x:c) cout << x << endl;

    return 0;
}