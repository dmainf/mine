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
    vector<int> a(2*n);
    rep(i, n) {
        cin >> a[i];
        a[n+i]=a[i];
    }
    ll sum=0;
    rep(i, n) sum+=a[i];
    int r=0;
    ll now=0;
    rep(l, 2*n) {
        while(r<2*n) {
            if(sum<now*10) break;
            now+=a[r];
            r++;
            //cout << now << endl;
            if(now*10==sum) {
                YES;
                return 0;
            }
        }
        now-=a[l];
    }
    NO;

    return 0;
}