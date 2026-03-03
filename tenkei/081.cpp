#include <bits/stdc++.h>
using namespace std;
#define rep(high,n) for(int high=0;high<(n);high++)
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> s(5009, vector<int>(5009, 0));
    //s[heigh][weight]
    rep(high, n) {
        int a, b;
        cin >> a >> b;
        s[a][b]++;
    }
	for(int i=1; i<=5000; i++) for(int j=1; j<=5000; j++) {
		s[i][j]+=s[i-1][j];
	}
	for(int i=1; i<=5000; i++) for(int j=1; j<=5000; j++) {
	    s[i][j]+=s[i][j-1];
	}
    int ans=0;
    for(int i=0; i<=5000-k-1; i++) for(int j=0; j<=5000-k-1; j++) {
        int tmp=s[i+k+1][j+k+1]-s[i][j+k+1]-s[i+k+1][j]+s[i][j];
        ans=max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}