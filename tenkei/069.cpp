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
    ll n, k;
    cin >> n >> k;
    //k (k-1) (k-2) (k-2) ...
    mint x=k;
    if(2<=n) x*=max(0LL, k-1);
    if(3<=n) {
        auto npow=[&](ll a, ll m)->mint{
            mint res=1;
            mint base=a;
            while(m>0){
                if(m&1)res*=base;
                base*=base;m>>=1;
            }
            return res;
        };
        x*=npow(max(0LL, k-2), n-2);
    }
    cout << x.val() << endl;

    return 0;
}