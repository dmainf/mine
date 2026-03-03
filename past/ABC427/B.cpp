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
    int n;
    cin >> n;
    auto f=[&](int x) {
        int sum=0;
        while(x>0) {
            sum+=x%10;
            x/=10;
        }
        return sum;
    };

    vector<int> a(n+1);
    a[0]=1;
    for(int i=1; i<=n; i++) {
        int sum=0;
        rep(j, i) sum+=f(a[j]);
        a[i]=sum;
    }
    cout << a[n] << endl;

    return 0;
}