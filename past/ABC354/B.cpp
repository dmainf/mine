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
    int n;
    cin >> n;
    vector<string> s(n);
    int t=0;
    rep(i, n) {
        cin >> s[i];
        int c; cin >> c;
        t+=c;
    }
    sort(all(s));
    rep(i, n)if(t%n==i) {
        cout << s[i] << endl;
    }

    return 0;
}
