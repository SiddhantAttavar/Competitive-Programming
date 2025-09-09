#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

void dfs(int u, int x, vector<vector<pair<int, int>>> &graph, vector<vector<bool>> &vis, vector<vector<int>> &dp) {
	int n = graph.size(), k = u / n;
	vis[x][u] = true;
	if (x > 0 and dp[x][u] == dp[x - 1][u] and !vis[x - 1][u]) {
		dfs(u, x - 1, graph, vis, dp);
	}
	for (auto [v, w] : graph[u % n]) {
		if (x > 0 and !vis[x - 1][v] and dp[x][u] == dp[x - 1][v] + w) {
			dfs(v, x - 1, graph, vis, dp);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n);
	rep(i, 0, m) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	vector<vector<int>> dp(n, vector<int>(n, 1e13));
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	vector<int> t(n);
	vector<int> v;
	dp[0][0] = 0;
	t[0] = 1e13;
	rep(i, 1, n) {
		rep(u, 0, n) {
			dp[i][u] = dp[i - 1][u];
		}
		rep(u, 0, n) {
			for (auto [v, w] : graph[u]) {
				dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
			}
		}
		t[i] = dp[i][n - 1];
		if (t[i] == 1e13) {
			continue;
		}

		while (v.size() >= 2 and (t[v[v.size() - 2]] - t[i]) * (v[v.size() - 1] - v[v.size() - 2]) > (t[v[v.size() - 2]] - t[v[v.size() - 1]]) * (i - v[v.size() - 2])) {
			v.pop_back();
		}
		v.push_back(i);
	}

	for (int i : v) {
		if (t[i] < 1e13) {
			dfs(n - 1, i, graph, vis, dp);
		}
	}

	vector<bool> res(n, true);
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (vis[i][j]) {
				res[j] = false;
			}
		}
	}
	cout << accumulate(res.begin(), res.end(), 0ll) << endl;
	rep(i, 0, n) {
		if (res[i]) {
			cout << i + 1 << ' ';
		}
	}
	cout << endl;
}
