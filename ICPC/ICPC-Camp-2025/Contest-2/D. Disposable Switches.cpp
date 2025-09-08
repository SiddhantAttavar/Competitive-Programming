#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

void dfs(int u, vector<vector<int>> &graph, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
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

	vector<vector<int>> rev_graph(n * n);
	vector<bool> vis(n * n, false);
	vector<int> dp(n, 1e18);
	vector<int> t(n);
	dp[0] = 0;
	t[0] = 1e18;
	rep(i, 1, n) {
		vector<int> ndp(dp.begin(), dp.end());
		rep(u, 0, n) {
			for (auto [v, w] : graph[u]) {
				if (dp[u] + w < ndp[v]) {
					ndp[v] = dp[u] + w;
					rev_graph[v + n * i] = {u + n * (i - 1)};
				}
				else if (dp[u] + w == ndp[v]) {
					rev_graph[v + n * i].push_back(u + n * (i - 1));
				}
			}
		}
		t[i] = ndp[n - 1];
		dp = ndp;
	}

	int z = 0;
	int k = 1e18;
	for (int i = n - 1; i >= 1; i--) {
		if (k >= t[i] - z) {
			dfs(n - 1 + n * i, rev_graph, vis);
		}
		k = min(k, t[i] - z);
		z = max(z, t[i]);
	}

	vector<bool> res(n, true);
	rep(i, 0, n * n) {
		if (vis[i]) {
			res[i % n] = false;
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
