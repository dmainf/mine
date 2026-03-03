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
using mint=modint;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, m; cin >> t >> m;
    mint::set_mod(m);
    const int MAX_SUM_C = 5001;
    std::vector<int> primes;
    std::vector<std::vector<int>> vp_fact;
    bool is_prime[MAX_SUM_C];
    auto sieve=[&](void) {
        std::fill(is_prime, is_prime + MAX_SUM_C, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p < MAX_SUM_C; ++p) {
            if (is_prime[p]) {
                for (int i = p * p; i < MAX_SUM_C; i += p)
                    is_prime[i] = false;
            }
        }
        for (int p = 2; p < MAX_SUM_C; ++p) {
            if (is_prime[p]) {
                primes.push_back(p);
            }
        }
    };
    auto precompute_vp_fact=[&](void) {
        sieve();
        vp_fact.resize(primes.size(), std::vector<int>(MAX_SUM_C, 0));
        for (int i = 0; i < primes.size(); ++i) {
            int p = primes[i];
            for (int n = 1; n < MAX_SUM_C; ++n) {
                vp_fact[i][n] = n / p;
                if (n / p > 0) {
                    vp_fact[i][n] += vp_fact[i][n / p];
                }
            }
        }
    };
    precompute_vp_fact();
    vector<mint> ans;
    while(t--) {
        int n; cin >> n;
        vector<int> c(n);
        rep(i, n) cin >> c[i];
        int total=0;
        rep(i, n) total+=c[i];
        mint tmp=1;
        rep(i, primes.size()) {
            int p=primes[i];
            if(total<p) break;
            long long exponent=vp_fact[i][total];
            for(int val:c) exponent-=vp_fact[i][val];
            if(exponent>0) tmp*=mint(p).pow(exponent);
        }
        ans.push_back(tmp);
    }
    for(mint x:ans) cout << x.val() << endl;

    return 0;
}