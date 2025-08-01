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
    int n, d;
    cin >> n >> d;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int ans=0;
    int tmp=0;
    rep(j, d) {
        bool flag=true;
        rep(i, n) if(s[i][j]!='o') {
            flag=false;
        }
        if(flag) tmp++;
        else tmp=0;
        ans=max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}