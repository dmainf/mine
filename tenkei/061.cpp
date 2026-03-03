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
    int q; cin >> q;
    list<int> lst;
    vector<int> ans;
    while(q--) {
        int t, x; cin >> t >> x;
        if(t==1) lst.push_front(x);
        if(t==2) lst.push_back(x);
        if(t==3) ans.push_back(*next(lst.begin(), x-1));
    }
    for(int x:ans) cout << x << endl;

    return 0;
}