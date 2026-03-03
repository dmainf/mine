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
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int ans=0;
    bool flag=true;
    int cnt=0;
    rep(time, x) {
        if(flag) {
            ans+=s;
            cnt++;
            if(cnt==a) {
                flag=false;
                cnt=0;
            }
        } else {
            cnt++;
            if(cnt==b) {
                flag=true;
                cnt=0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}