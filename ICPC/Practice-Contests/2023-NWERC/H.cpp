#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void dfs(int u, vector<vi> &graph, vi &vis, vi &l) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis, l);
		}
	}
	l.push_back(u);
}

bool check(vi &comp, vi &vis, vi &l, vector<vi> &graph) {
	l.clear();
	for (int i : comp) {
		vis[i] = false;
		// cout << i << ' ';
	}
	// cout << endl;
	for (int i : comp) {
		if (!vis[i]) {
			dfs(i, graph, vis, l);
		}
	}
	reverse(all(l));
	// for (int i : l) {
	// 	cout << i << ' ';
	// }
	// cout << "d\n";
	
	for (int i : comp) {
		vis[i] = false;
	}
	set<int> s(all(comp));
	for (int i : l) {
		vis[i] = true;
		for (int j : graph[i]) {
			if (vis[j] and s.count(j)) {
				return false;
			}
		}
	}
	return true;
}

void solve() {
    int n, m;
	cin >> n >> m;

	vector<vi> graph(n), adj(n);
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;

		graph[a - 1].push_back(b - 1);
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}

	vi vis(n, false);
	vector<vi> comp;
	rep(i, 0, n) {
		if (!vis[i]) {
			comp.push_back({});
			dfs(i, adj, vis, comp.back());
		}
	}

	vector<pii> res;
	vis = vi(n, false);
	vi s(n, false);
	for (vi &v : comp) {
		if (sz(v) == 1) {
			continue;
		}

		vi l;
		if (check(v, vis, l, graph)) {
			rep(i, 1, sz(l)) {
				res.push_back({l[i - 1], l[i]});
			}
			continue;
		}

		bool flag = false;
		for (int i : v) {
			vi nv = v;
			nv.erase(find(all(nv), i));
			if (check(nv, vis, l, graph)) {
				flag = true;
				res.push_back({i, l[0]});
				rep(i, 1, sz(l)) {
					res.push_back({l[i - 1], l[i]});
				}
				res.push_back({l.back(), i});
				break;
			}
		}
		if (!flag) {
			cout << -1 << endl;
			return;
		}
	}

	cout << sz(res) << endl;
	for (auto [u, v] : res) {
		cout << u + 1 << ' ' << v + 1 << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
