#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://cp-algorithms.com/graph/dinic.html
 * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
 * $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */
// #pragma once

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

pii dfs(int i, int j, vector<vi> &vis, vector<vi> &a, vector<vi> &b, int c) {
	vis[i][j] = c;
	int s = 1, w = a[i][j] == b[i][j];
	vector<pii> l = {
		{i - 1, j},
		{i + 1, j},
		{i, j - 1},
		{i, j + 1}
	};
	for (auto [x, y] : l) {
		if (min(x, y) < 0 or x >= sz(a) or y >= sz(a[0])) {
			continue;
		}
		if (vis[x][y] == -1 and a[i][j] == a[x][y]) {
			auto [t, z] = dfs(x, y, vis, a, b, c);
			s += t;
			w += z;
		}
	}
	return {s, w};
}

void solve() {
    int n, m;
	cin >> n >> m;
	
	vector<vi> a(n, vi(m)), b(n, vi(m));
	rep(i, 0, n) {
		string s;
		cin >> s;
		rep(j, 0, m) {
			a[i][j] = s[j] == '1';
		}
	}
	rep(i, 0, n) {
		string s;
		cin >> s;
		rep(j, 0, m) {
			b[i][j] = s[j] == '1';
		}
	}

	vector<vi> vis(n, vi(m, -1));
	vector<array<int, 3>> v;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (vis[i][j] == -1) {
				auto [s, x] = dfs(i, j, vis, a, b, sz(v));
				v.push_back({s, x, a[i][j]});
			}
		}
	}

	set<pii> e;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (i and vis[i][j] != vis[i - 1][j]) {
				if (a[i][j]) {
					e.insert({vis[i - 1][j], vis[i][j]});
				}
				else {
					e.insert({vis[i][j], vis[i - 1][j]});
				}
			}
			if (j and vis[i][j] != vis[i][j - 1]) {
				if (a[i][j]) {
					e.insert({vis[i][j - 1], vis[i][j]});
				}
				else {
					e.insert({vis[i][j], vis[i][j - 1]});
				}
			}
		}
	}

	Dinic d(sz(v) + 2);
	int s = sz(v), t = sz(v) + 1, res = 0;
	rep(i, 0, sz(v)) {
		res += max(v[i][1], v[i][0] - v[i][1]);
		if (2 * v[i][1] >= v[i][0]) {
			continue;
		}
		if (v[i][2]) {
			d.addEdge(i, t, v[i][0] - 2 * v[i][1]);
		}
		else {
			d.addEdge(s, i, v[i][0] - 2 * v[i][1]);
		}
	}
	for (auto [u, v] : e) {
		d.addEdge(u, v, n * m);
	}
	cout << n * m - res + d.calc(s, t) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
