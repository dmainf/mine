#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<tuple<ll,ll,ll,int>> kyaku;
    for(int i = 0; i < n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        kyaku.emplace_back(a, b, c, i);
    }
    queue<tuple<int,ll,ll>> wait;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<ll> ans(n);
    int capa = 0;
    int arrival_idx = 0;
    int cnt = 0;
    while(cnt < n) {
        ll next_time = LLONG_MAX;
        if(arrival_idx < n) {
            next_time = min(next_time, get<0>(kyaku[arrival_idx]));
        }
        if(!pq.empty()) {
            next_time = min(next_time, pq.top().first);
        }
        if(!wait.empty() && pq.empty() && arrival_idx >= n) {
            break;
        }
        while(!pq.empty() && pq.top().first <= next_time) {
            capa -= pq.top().second;
            pq.pop();
        }
        while(arrival_idx < n && get<0>(kyaku[arrival_idx]) <= next_time) {
            auto [a, b, c, idx] = kyaku[arrival_idx];
            wait.push({idx, b, c});
            arrival_idx++;
        }
        bool entered = false;
        while(!wait.empty()) {
            auto [idx, b, c] = wait.front();
            if(capa + c <= k) {
                wait.pop();
                capa += c;
                ans[idx] = next_time;
                pq.push({next_time + b, c});
                cnt++;
                entered = true;
            } else {
                break;
            }
        }
    }
    for(ll x : ans) cout << x << endl;

    return 0;
}