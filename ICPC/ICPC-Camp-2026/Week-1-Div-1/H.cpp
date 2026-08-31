#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi get(int s, vector<vector<pii>> &graph) {
	vi d(sz(graph), 1e18);
	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [x, u] = pq.top();
		pq.pop();

		if (x != d[u]) {
			continue;
		}

		for (auto [v, w] : graph[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
	return d;
}

void solve() {
    int n, m, k, s, t;
	cin >> n >> m >> k >> s >> t;

	s--;
	t--;

	vector<vector<pii>> graph(n);
	rep(i, 0, m) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	vi v(k);
	rep(i, 0, k) {
		cin >> v[i];
		v[i]--;
	}

	vi d = get(s, graph), z = get(t, graph);

	long double res = d[t];
	sort(all(v), [&](int i, int j) {
		return z[i] < z[j];
	});

	int x = z[v[0]], y = 1e18;
	for (int i : v) {
		y = min(y, d[i]);
	}
	rep(i, 1, k) {
		res = min(res, y + ((long double) (x + k)) / i);
		x += z[v[i]];
	}
	cout << fixed << setprecision(15) << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
