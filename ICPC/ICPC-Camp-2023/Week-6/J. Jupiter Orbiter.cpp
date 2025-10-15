#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define vi vector<int>
#define ll long long
#define sz(x) (int) x.size()

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

int32_t main() {
	setup();

	int n, q, s;
	input(n, q, s);

	vector<int> v(s), c(q);
	arrput(v);
	arrput(c);

	rep(i, 0, s) {
		v[i]--;
	}

	vector<int> d(n);
	vector<vector<int>> a(q, vector<int>(n, 0));
	int t = 0;
	rep(i, 0, n) {
		input(d[i]);
		rep(j, 0, s) {
			int x;
			input(x);
			a[v[j]][i] += x;
			t += x;
		}
	}

	int l = 0, r = 1;
	vector<vector<int>> b(q, vector<int>(n));
	rep(i, 0, q) {
		rep(j, 0, n) {
			b[i][j] = r;
			r += 2;
		}
	}
	vector<int> x(n);
	rep(i, 0, n) {
		x[i] = r;
		r++;
	}

	Dinic f(r + 1);
	rep(j, 0, n) {
		rep(i, 0, q) {
			f.addEdge(l, b[i][j], a[i][j]);
			if (j) {
				f.addEdge(b[i][j - 1] + 1, b[i][j], c[i]);
			}
			f.addEdge(b[i][j], b[i][j] + 1, c[i]);
			f.addEdge(b[i][j] + 1, x[j], c[i]);
		}
		f.addEdge(x[j], r, d[j]);
	}

	if (f.calc(l, r) == t) {
		print("possible");
	}
	else {
		print("impossible");
	}
}
