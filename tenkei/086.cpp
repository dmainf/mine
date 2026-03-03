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
#include <atcoder/modint>
using namespace atcoder;
using mint=modint1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> x(q), y(q), z(q);
    vector<ll> w(q), W(q);
    rep(i, q) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--;y[i]--;z[i]--;
    }
    //4 2
    //1 2 3 50
    //2 3 4 45
    mint ans=1;
    rep(bit, 60) {
        //retribute a degit of bit
        rep(qi, q) W[qi]=(w[qi]>>bit)&1;
        ll ret=0;
        rep(i, (1<<n)) {
            vector<ll> tmp(n, 0);
            //transfer i into bit
            rep(bbit, n) tmp[bbit]=(i>>bbit)&1;
            bool flag=true;
            rep(qi, q) if((tmp[x[qi]]|tmp[y[qi]]||tmp[z[qi]])!=W[qi]) {
                flag=false;
            }
            if(flag) ret++;
        }
        ans*=ret;
    }
    cout << ans.val() << endl;

    return 0;
}