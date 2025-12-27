#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int u, int p, int r, vector<vi> &graph, vector<array<int, 3>> &dp) {
    int x = 0, y = 0, z = 0;
    for (int v : graph[u]) {
        if (v != p) {
            dfs(v, u, r, graph, dp);
            x += dp[v][0];
            y = max(y, dp[v][1]);
            z = max(z, dp[v][2]);
        }
    }

    y++;

    if (y == r + 1) {
        dp[u] = {x + 1, 0, r};
        return;
    }

    if (z >= y) {
        dp[u] = {x, 0, z - 1};
        return;
    }

    dp[u] = {x, y, max(0ll, z - 1)};
}

bool check(vector<vi> &graph, int r, int k) {
    vector<array<int, 3>> dp(sz(graph));
    dfs(0, -1, r, graph, dp);
    return dp[0][0] + (dp[0][1] > 0) <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vi> graph(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;

        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int l = 0, r = n, res = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(graph, m, k)) {
            res = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
