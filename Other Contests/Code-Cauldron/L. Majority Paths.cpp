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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T a, T b);
	int n; vector<T> seg;
	SegTree(int _n, T id, T _cmb(T, T)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] += val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

void dfs1(int u, int p, vector<vi> &graph, vi &a, vi &d, vi &t) {
	d[u] += a[u] ? 1 : -1;
	for (int v : graph[u]) {
		if (v != p) {
			d[v] = d[u];
			dfs1(v, u, graph, a, d, t);
			t[u] += t[v];
		}
	}
}

int dfs2(int u, int p, vector<vi> &graph, vi &a, vi &d, vi &t, vector<vi> &o, SegTree<int> &s, bool b = false) {
	int k = -1, n = sz(graph);
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		if (k == -1 or t[v] > t[k]) {
			k = v;
		}
	}

	int res = a[u];
	for (int v : graph[u]) {
		if (v == k or v == p) {
			continue;
		}
		res += dfs2(v, u, graph, a, d, t, o, s);
	}
	if (k != -1) {
		res += dfs2(k, u, graph, a, d, t, o, s, true);
		swap(o[u], o[k]);
	}
	int l = max(-n, 2 * d[u] - d[u] - (a[u] ? 1 : -1) + 1);
	if (l <= n) {
		res += s.query(l + n, n + n);
	}
	s.upd(d[u] + n, 1);
	o[u].push_back(d[u]);
	for (int v : graph[u]) {
		if (v == k or v == p) {
			continue;
		}
		for (int x : o[v]) {
			int l = max(-n, 2 * d[u] - x - (a[u] ? 1 : -1) + 1);
			if (l <= n) {
				res += s.query(l + n, n + n);
			}
		}
		for (int x : o[v]) {
			s.upd(x + n, 1);
			o[u].push_back(x);
		}
	}

	if (!b) {
		for (int x : o[u]) {
			s.upd(x + n, -1);
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		vector<vi> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vi d(n, 0), t(n, 1);
		dfs1(0, -1, graph, a, d, t);

		vector<vi> o(n);
		SegTree<int> s(2 * n + 1, 0, [](int a, int b) {
			return a + b;
		});
		print(dfs2(0, -1, graph, a, d, t, o, s, true));
	}
}

