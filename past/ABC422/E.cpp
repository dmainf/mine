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
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    int need=n/2+1;
    auto check=[&](int i, int j) {
        ll dx=x[j]-x[i];
        ll dy=y[j]-y[i];
        ll cnt=0;
        rep(k, n) {
            ll tmp=(x[k]-x[i])*dy-(y[k]-y[i])*dx;
            if(tmp==0) cnt++;
        }
        if(need<=cnt) {
            ll a=y[j]-y[i];
            ll b=x[i]-x[j];
            ll c=-(a*x[i]+b*y[i]);
            YES;
            cout << a << " " << b << " " << c  << endl;
            return true;
        }
        return false;
    };
    std::random_device rd;  // ハードウェア乱数生成器
    std::mt19937 mt(rd());   // メルセンヌ・ツイスタ法の生成器
    // 0から100までの一様分布の乱数を生成
    std::uniform_int_distribution<int> dist(0, n-1);
    rep(x, 30) {
        int i=dist(mt);
        int j=dist(mt);
        if(i==j) continue;
        if(check(i, j)) return 0;
    }
    NO;

    return 0;
}