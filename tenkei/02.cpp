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
    int n; cin >> n;
    auto check=[&](string s) -> bool {
        int cnt=0;
        rep(i, n) {
            if(s[i]=='(') cnt++;
            else cnt--;
            if(cnt<0) return false;
        }
        return (cnt==0);
    };
    vector<string> ans;
    rep(mask, 1<<n) {
        string s="";
        rep(bit, n) {
            if((mask>>bit)&1) s+='(';
            else s+=')';
        }
        if(check(s)) ans.push_back(s);
    }
    sort(all(ans));
    for(string s:ans) cout << s << endl;

    return 0;
}