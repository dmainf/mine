#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define drep(i, n) for(int i=(n)-1; i>=0; i--)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define nsort(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sumx=0, sumy=0;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        sumx+=x;
        sumy+=y;
    }
    if(sumx>sumy) cout << "Takahashi" << endl;
    else if(sumx==sumy) cout << "Draw" << endl;
    else cout << "Aoki" << endl;

    return 0;
}
