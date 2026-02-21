#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dfs(int u, int p, vector<vector<pii>> &graph, vector<array<int, 3>> &x, vector<array<int, 8>> &dp, vi &d) {
    rep(i, 0, 8) {
        dp[u][i] = d[u] + 
            (i & 1 ? x[u][0] : -x[u][0]) +
            (i & 2 ? x[u][1] : -x[u][1]) +
            (i & 4 ? x[u][2] : -x[u][2]);
    }

    int res = 0;
    for (auto [v, w] : graph[u]) {
        if (v == p) {
            continue;
        }

        d[v] = d[u] + w;
        res = max(res, dfs(v, u, graph, x, dp, d));
        rep(i, 0, 8) {
            res = max(res, dp[u][i] + dp[v][i ^ 7] - 2 * d[u]);
            dp[u][i] = max(dp[u][i], dp[v][i]);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<pii>> graph(n);
    rep(i, 0, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }

    vector<array<int, 3>> x(n);
    rep(i, 0, n) {
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    }
    
    vector<array<int, 8>> dp(n);
    vi d(n, 0);
    cout << dfs(0, -1, graph, x, dp, d) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
