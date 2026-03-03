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
vector<pair<ll,ll>> primefac(ll N) {
    vector<pair<ll,ll>> res;
    for(ll a=2;a*a<=N;++a){
        if(N%a!=0) continue;
        ll ex=0;
        while(N%a==0){++ex;N/=a;}
        res.push_back({a,ex});
    }
    if(N!=1)res.push_back({N,1});
    return res;
}
bool is_prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    auto fac=primefac(n);
    int cnt=0;
    for(auto x:fac) cnt+=x.second;
    int tmp=1;
    rep(i, n) {
        if(cnt<=tmp) {
            cout << i << endl;
            return 0;
        }
        tmp*=2;
    }

    return 0;
}