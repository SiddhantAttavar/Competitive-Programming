#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("hard.in", "r", stdin);
    freopen("hard.out", "w", stdout);

    vector<vector<int>> dp(61, vector<int>(61, 1e18));
    vector<vector<pair<int, int>>> par(61, vector<pair<int, int>>(61, {-1, -1}));
    rep(i, 1, 61) {
        dp[i][i] = 1;
    }
    rep(i, 1, 61) {
        rep(j, 1, 61) {
            rep(k, 1, i) {
                if (dp[k][j] + dp[i - k][j] < dp[i][j]) {
                    dp[i][j] = dp[k][j] + dp[i - k][j];
                    par[i][j] = {k, j};
                }
            }
            rep(k, 1, j) {
                if (dp[i][k] + dp[i][j - k] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[i][j - k];
                    par[i][j] = {i, k};
                }
            }
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        queue<tuple<int, int, int, int>> q;
        q.push({0, 0, n, m});
        vector<tuple<int, int, int>> res;
        while (!q.empty()) {
            int x, y, n, m;
            tie(x, y, n, m) = q.front();
            q.pop();

            if (n == m) {
                res.push_back({x, y, n});
                continue;
            }

            if (par[n][m].first < n) {
                q.push({x, y, par[n][m].first, par[n][m].second});
                q.push({x + par[n][m].first, y, n - par[n][m].first, par[n][m].second});
            }
            else {
                q.push({x, y, par[n][m].first, par[n][m].second});
                q.push({x, y + par[n][m].second, par[n][m].first, m - par[n][m].second});
            }
        }

        cout << res.size() << endl;
        // cout << dp[n][m] << endl;
        for (auto [x, y, n] : res) {
            cout << x << ' ' << y << ' ' << n << endl;
        }
    }
}
