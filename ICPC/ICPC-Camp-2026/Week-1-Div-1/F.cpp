#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

int dfs(int u, vector<vi> &graph, vi &vis, vi &p, bool flag) {
	vis[u] = true;
	if (flag) {
		return vis[p[u]] ? 0 : dfs(p[u], graph, vis, p, false);
	}

	int res = 1;
	for (int v : graph[u]) {
		if (v != p[u] and !vis[v]) {
			res += dfs(v, graph, vis, p, true);
		}
	}
	return res;
}

void solve() {
    int h, w;
	cin >> h >> w;

	vector<string> v(h);
	rep(i, 0, h) {
		cin >> v[i];
	}

	vector<vi> a(h, vi(w, -1));
	int x = 0, y = 0;
	rep(i, 0, h) {
		rep(j, 0, w) {
			if (v[i][j] == '.') {
				continue;
			}
			if ((i + j) % 2) {
				a[i][j] = x++;
			}
			else {
				a[i][j] = y++;
			}
		}
	}
	
	vector<vi> g(x);
	vector<vi> graph(x + y);
	rep(i, 0, h) {
		rep(j, 0, w) {
			if (!((i + j) % 2) or a[i][j] == -1) {
				continue;
			}
			vector<pii> l = {
				{i - 1, j},
				{i + 1, j},
				{i, j - 1},
				{i, j + 1}
			};
			for (auto [u, v] : l) {
				if (min(u, v) >= 0 and u < h and v < w and a[u][v] != -1) {
					g[a[i][j]].push_back(a[u][v]);
					graph[a[i][j]].push_back(a[u][v] + x);
					graph[a[u][v] + x].push_back(a[i][j]);
				}
			}
		}
	}
	
	vi btoa(y, -1), match(x + y, -1);
	int z = hopcroftKarp(g, btoa);
	
	if ((2 * z + 1) != (x + y)) {
		cout << 0 << endl;
		return;
	}

	rep(i, 0, y) {
		if (btoa[i] != -1) {
			match[i + x] = btoa[i];
			match[btoa[i]] = i + x;
		}
	}
	
	vi vis(x + y, false);
	int u = find(all(match), -1) - match.begin();
	cout << dfs(u, graph, vis, match, false) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
