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
    vector<int> a;
    int q;
    cin >> q;
    while(q--){
        int com;
        cin >> com;
        if(com==0) { 
            int x;
            cin >> x;
            a.push_back(x);
        }
        if(com==1) {
            int p;
            cin >> p;
            cout << a[p] << endl;
        }
        if(com==2) a.pop_back();
    }
    return 0;
}