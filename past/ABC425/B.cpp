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
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    rep(i, n) cin >> a[i];
    rep(i, n) p[i]=i+1;
    do {
        bool flag=true;
        rep(i, n) {
            if(!(a[i]==-1 || a[i]==p[i])) flag=false;
        }
        if(flag) {
            YES;
            rep(i, n) cout << p[i] << " ";
            cout << endl;
            return 0;
        }
    } while(next_permutation(all(p)));
    NO;

    return 0;
}