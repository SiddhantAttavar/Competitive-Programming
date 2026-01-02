#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs1(int u, vector<vi> &graph, vi &c) {
	for (int v : graph[u]) {
		if (c[v] == -1) {
			c[v] = 1 - c[u];
			if (!dfs1(v, graph, c)) {
				return false;
			}
		}
		else if (c[u] == c[v]) {
			return false;
		}
	}
	return true;
}

void dfs2(int u, int p, vector<vi> &graph, vector<bool> &cycle) {
	cycle[u] = false;
	for (int v : graph[u]) {
		if (v != p and sz(graph[v]) == 2) {
			dfs2(v, u, graph, cycle);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vi> graph(n);
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vi c(n, -1);
	c[0] = 0;
	if (dfs1(0, graph, c)) {
		cout << 2 << endl;
		for (int i : c) {
			cout << i + 1 << ' ';
		}
		cout << endl;
		return;
	}
	c.assign(n, -1);

	int r = -1;
	vi deg3;
	rep(i, 0, n) {
		if (sz(graph[i]) == 1 or sz(graph[i]) > 3) {
			r = i;
			break;
		}
		else if (sz(graph[i]) == 3) {
			deg3.push_back(i);
		}
	}
	if (r == -1 and sz(deg3) == 2) {
		rep(i, 0, n) {
			if (sz(graph[i]) == 2) {
				r = i;
				break;
			}
		}
	}
	if (r == -1 and sz(deg3) == 4) {
		r = deg3[0];
	}
	assert(r != -1);

	vector<bool> cycle(n, true);
	dfs2(r, -1, graph, cycle);

	c[r] = 2;
	if (accumulate(cycle.begin(), cycle.end(), 0ll) % 2 == 1) {
		int u = -1;
		rep(i, 0, n) {
			if (cycle[i] and find(graph[i].begin(), graph[i].end(), r) == graph[i].end()) {
				u = i;
				break;
			}
		}
		if (u != -1) {
			c[u] = 2;
		}
		else {
			rep(i, 0, n) {
				if (cycle[i]) {
					c[i] = 3;
					break;
				}
			}
		}
	}

	rep(i, 0, n) {
		if (c[i] == -1) {
			c[i] = 0;
			dfs1(i, graph, c);
		}
	}

	cout << *max_element(c.begin(), c.end()) + 1 << endl;
	for (int i : c) {
		cout << i + 1 << ' ';
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
