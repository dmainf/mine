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
    int n, q;
    cin >> n >> q;
    vector<int> t(q), x(q), y(q), v(q);
    rep(i, q) {
        cin >> t[i] >> x[i] >> y[i] >> v[i];
        x[i]--; y[i]--;
    }
    vector<int> sum(n-1, 0);
    rep(i, q) if(t[i]==0) sum[x[i]]=v[i];
    vector<ll> pot(n, 0);
    rep(i, n-1) pot[i+1]=sum[i]-pot[i];
    set<int> st;
    for(int i=-1; i<n; i++) st.insert(i);
    //a[i]+a[i+1]=sum[i]
    //a[1]=sum[0]-a[0]
    //a[2]  =sum[1]-a[1]
    //      =sum[1]-(sum[0]-a[0])
    //      =sum[1]-sum[0]+a[0]
    //a[3]  =sum[2]-a[2]
    //      =sum[2]-sum[1]+sum[0]-a[0]
    //a[i]=pot[i]+(-1)^i*a[0]
    rep(i, q) {
        if(t[i]==0) st.erase(x[i]);
        else {
            int l=min(x[i], y[i]);
            int r=max(x[i], y[i]);
            auto it=st.lower_bound(l);
            //a[x]=pot[x]+(-1)^x*a[0]
            //a[y]=pot[y]+(-1)^y*a[0]
            //when a[x]=v, (-1)^x*a[0]=v-pot[x]
            //insert a[y]=pot[y]+(-1)^(y-x)*(v-pot[x])
            if(r-1<*it) {
                if((r-l)%2==0) cout << pot[y[i]]+(v[i]-pot[x[i]]) << endl;
                else cout << pot[y[i]]-(v[i]-pot[x[i]]) << endl;
            } else cout << "Ambiguous" << endl;
        }
    }

    return 0;
}