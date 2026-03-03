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
    int h, w; cin >> h >> w;
    int ans=0;
    if(h==1 || w==1) {
        cout << h*w << endl;
        return 0;
    }
    rep(i, h) if(i%2==0) {
        rep(j, w) if((i+j)%2==0) ans++;
    }
    cout << ans << endl;

    return 0;
}