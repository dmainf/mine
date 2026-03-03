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
    int n, m, k; cin >> n >> m >> k;
    multiset<int> h, b;
    rep(i, n) {
        int x; cin >> x;
        h.insert(x);
    }
    rep(i, m) {
        int x; cin >> x;
        b.insert(x);
    }
    int cnt=0;
    for(int head:h) {
        auto it=b.lower_bound(head);
        if(it==b.end()) continue;
        cnt++;
        b.erase(it);
    }
    if(k<=cnt) YES;
    else NO;

    return 0;
}