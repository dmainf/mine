#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using ull=unsigned long long;
using pi=pair<int,int>;
const int di[]={+1,-1,+0,+0};
const int dj[]={+0,+0,+1,-1};
const int INF=1e9;
long long base8_to_long(string N) {
	long long res = 0;
	for (int i = 0; i < N.size(); ++i) {
		res = res * 8 + int(N[i] - '0');
	}
	return res;
}
string long_to_base9(long long N) {
	if (N == 0) {
		return "0";
	}
	string res;
	while (N > 0) {
		res = char(N % 9 + '0') + res;
		N /= 9;
	}
	return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    int k;
    cin >> n >> k;
    rep(i, k) {
        n=long_to_base9(base8_to_long(n));
        rep(j, n.size()) {
            if(n[j]=='8') n[j]='5';
        }
    }
    cout << n << endl;

    return 0;
}