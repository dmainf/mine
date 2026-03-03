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
const int MOD=100000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    //5 3
    //5+5       =10
    //10+(1+0)  =11 1
    //11+(1+1)  =13 2
    //13+(1+3)  =17 4
    //17+(1+7)  =25 8
    //25+(2+5)  =32 7
    //32+(3+2)  =37 5
    vector<int> seen(MOD, -1);
    int now=n;
    int step=0;
    while(0<k) {
        if(seen[now]!=-1) k%=step-seen[now];
        seen[now]=step;
        if(k==0) break;
        int add=0;
        int temp=now;
        while(0<temp) {
            add+=temp%10;
            temp/=10;
        }
        now=(now+add)%MOD;
        step++;
        k--;
    }
    cout << now << endl;

    return 0;
}