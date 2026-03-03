#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ll=long long;
using pi=pair<char,ll>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    string s;
    cin >> n >> s;
    vector<pi> p;
    for(char c:s) {
        if(!p.empty() && p.back().first==c) p.back().second++;
        else p.push_back({c, 1});
    }
    ll all=0, dame=0;
    all=n*(n+1)/2;
    for(auto [c, x]:p) dame+=x*(x+1)/2;
    cout << all-dame << endl;

    return 0;
}