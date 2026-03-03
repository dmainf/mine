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
//const ll INF=1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, L, k; cin >> n >> L >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> yokans;
    int pre=0;
    rep(i, n) {
        yokans.push_back(a[i]-pre);
        pre=a[i];
    }
    yokans.push_back(L-pre);
    auto f=[&](int x) -> bool {
        int cnt=0;
        int tmp=0;
        for(int yokan:yokans) {
            if(tmp+yokan<=x) {
                tmp+=yokan;
            } else {
                cnt++;
                tmp=0;
            }
        }
        return (cnt<k+1);
    };
    int l=0, r=INF;
    while(l<=r) {
        int mid=(l+r)/2;
        if(f(mid)) r=mid-1;
        else l=mid+1;
    }
    cout << l << endl;

    return 0;
}