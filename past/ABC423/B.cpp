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
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    vector<bool> room(n+1, false);
    room[0]=room[n]=true;
    for(int i=1; i<=n; i++) {
        if(l[i-1]==0) room[i]=true;
        else break;
    }
    for(int i=n-1; i>=0; i--) {
        if(l[i]==0) room[i]=true;
        else break;
    }
    int ans=0;
    rep(i, n+1) if(!room[i]) ans++;
    cout << ans << endl;

    return 0;
}