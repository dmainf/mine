#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s.length() == 0) {
        cout << 0 << endl;
        return;
    }

    vector<pair<char, int>> blocks;
    blocks.emplace_back(s[0], 1);
    for (int i = 1; i < n; ++i) {
        if (s[i] == blocks.back().first) {
            blocks.back().second++;
        } else {
            blocks.emplace_back(s[i], 1);
        }
    }

    int m = blocks.size();
    vector<vector<ll>> dp(m + 1, vector<ll>(2, -1));

    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 0; i < m; ++i) {
        // i+1番目のブロックまでを'0'にするコスト
        ll cost_to_0;
        if (blocks[i].first == '0') {
            cost_to_0 = min(dp[i][0], dp[i][1] + i);
        } else { // blocks[i].first == '1'
            cost_to_0 = min(dp[i][0] + blocks[i].second, dp[i][1] + i);
        }
        dp[i + 1][0] = cost_to_0;

        // i+1番目のブロックまでを'1'にするコスト
        ll cost_to_1;
        if (blocks[i].first == '1') {
            cost_to_1 = min(dp[i][1], dp[i][0] + i);
        } else { // blocks[i].first == '0'
            cost_to_1 = min(dp[i][1] + blocks[i].second, dp[i][0] + i);
        }
        dp[i + 1][1] = cost_to_1;
    }

    cout << min(dp[m][0], dp[m][1]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}