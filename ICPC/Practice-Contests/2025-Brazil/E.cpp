#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

vi dist(vector<vi> &graph, int u) {
	vector<pii> d(sz(graph), {-1, false});
	d[u] = {0, false};
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (d[v].first == -1) {
				d[v] = {d[u].first + 1, d[u].second};
				q.push(v);
			}
			else if (d[v].first == d[u].first + 1) {
				d[v].second = true;
			}
		}
	}
	vi res(sz(graph), -1);
	res[u] = 0;
	rep(i, 0, sz(graph)) {
		if (d[i].first > 1) {
			res[i] = 2 * d[i].first - d[i].second;
		}
	}
	return res;
}

void add(set<pii> &e, vector<vi> &graph, vi &x) {
	rep(u, 0, sz(graph)) {
		if (x[u] != 4) {
			continue;
		}
		for (int v : graph[u]) {
			if (x[v] == -1) {
				x[v] = 2;
			}
		}
	}
	rep(u, 0, sz(graph)) {
		if (x[u] != 3) {
			continue;
		}
		bool flag = false;
		for (int v : graph[u]) {
			if (x[v] == 2) {
				flag = true;
			}
		}
		if (!flag) {
			continue;
		}
		for (int v : graph[u]) {
			if (x[v] == -1) {
				x[v] = 1;
			}
		}
	}
	rep(u, 0, sz(graph)) {
		for (int v : graph[u]) {
			if (x[v] != -1 and x[u] != -1 and x[v] == x[u] - 1) {
				e.insert({min(u, v), max(u, v)});
			}
		}
	}
}

void check(vector<pii> &res, vector<vi> &graph) {
	int n = sz(graph), m = 0;
	rep(u, 0, n) {
		m += sz(graph[u]);
	}
	vector<vi> adj(n);
	for (auto [u, v] : res) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	set<pii> e;
	rep(u, 0, n) {
		for (int v : adj[u]) {
			e.insert({u, v});
		}
		if (sz(e) > m) {
			cout << "*" << endl;
			return;
		}
		for (int v : adj[u]) {
			for (int w : adj[u]) {
				if (v != w) {
					// cout << v << ' ' << w << endl;
					e.insert({v, w});
				}
				if (sz(e) > m) {
					cout << "*" << endl;
					return;
				}
			}
		}
	}
	
	adj = vector<vi>(n);
	for (auto [u, v] : e) {
		adj[u].push_back(v);
	}
	
	rep(u, 0, n) {
		sort(all(adj[u]));
		sort(all(graph[u]));
	}
	
	if (adj != graph) {
		cout << "*" << endl;
		return;
	}

	if (sz(res) != n - 1) {
		cout << "*" << endl;
		return;
	}

	for (auto [u, v] : res) {
		cout << u + 1 << ' ' << v + 1 << endl;
	}
}

void solve() {
    int n, m;
	cin >> n >> m;

	vi pow2(n, 1);
	rep(i, 1, n) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}

	vi s(n, 0);
	vector<vi> graph(n);
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	set<pii> e;
	int c = 0;
	rep(u, 0, n) {
		c += sz(graph[u]) == n - 1;
	}

	if (c == n) {
		rep(i, 1, n) {
			e.insert({0, i});
		}
	}
	else if (c == 2) {
		int p = -1, q = -1, r = -1;
		rep(u, 0, n) {
			if (sz(graph[u]) < n - 1) {
				r = u;
				continue;
			}
			if (p == -1) {
				p = u;
			}
			else {
				q = u;
			}
		}

		vi x = dist(graph, r);

		e.insert({min(p, q), max(p, q)});
		rep(u, 0, n) {
			if (u == p or u == q) {
				continue;
			}
			if (x[u] <= 0) {
				e.insert({min(u, p), max(u, p)});
			}
			else if (x[u] == 3) {
				e.insert({min(u, q), max(u, q)});
			}
		}	
	}
	else {
		int u = sz(graph[0]) == n - 1;
		vi x = dist(graph, u);
		u = max_element(all(x)) - x.begin();
		x = dist(graph, u);
		add(e, graph, x);
		u = max_element(all(x)) - x.begin();
		x = dist(graph, u);
		add(e, graph, x);
	}

	vector<pii> res(all(e));
	check(res, graph);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
