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
#include <atcoder/string>
using namespace atcoder;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n=s.size();
    string t=s;
    reverse(all(t));
    t+=s;
    //E E R T T R E E
    //8 1 0 0 0 0 2 1
    vector<int> z=z_algorithm(t);
    rep(i, n) {
        if(z[n+i]==n-i) {
            string ans=s;
            ans+=t.substr(n-i, i);
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}