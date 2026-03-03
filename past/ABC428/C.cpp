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
    int q; cin >> q;
    vector<pair<int,int>> st;
    int bal=0, min_bal=0;
    while(q--) {
        int op; cin >> op;
        if(op==1) {
            char c; cin >> c;
            st.push_back({bal, min_bal});
            if(c=='(') bal++;
            else bal--;
            min_bal=min(min_bal, bal);
        } else {
            auto [pre_bal, pre_mn]=st.back();
            st.pop_back();
            bal=pre_bal;
            min_bal=pre_mn;
        }
        if(bal==0 && min_bal>=0) YES;
        else NO;
    }

    return 0;
}