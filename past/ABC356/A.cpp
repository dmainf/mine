#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    rep(i, n) a[i]=i+1;
    reverse(a.begin() + (l - 1), a.begin() + r);
    rep(i, n) cout << a[i] << " \n"[i==n-1];

    return 0;
}
