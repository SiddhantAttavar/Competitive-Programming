#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

void dfs1(int u, int p, vector<vi> &tree, vi &x) {
	for (int v : tree[u]) {
		if (v != p) {
			dfs1(v, u, tree, x);
			x[u] += x[v];
		}
	}
}

void add(int x, int k, vector<pii> &l, map<int, int> &t, SegTree<int> &s) {
	l.push_back({x, k});
	s.upd(t[x], -1);
	t[x] += k;
	s.upd(t[x], 1);
}

void erase(SegTree<int> &s, map<int, int> &t, vector<pii> &l) {
	for (auto [x, k] : l) {
		s.upd(t[x], -1);
		t[x] -= k;
		s.upd(t[x], 1);
	}
	l.clear();
}

void dfs2(int u, int p, int n, vector<vi> &tree, vi &x, SegTree<int> &s, map<int, int> &t, vector<pii> &l, vector<vector<pii>> &q, vi &res, vi &c) {
	int w = -1;
	for (int v : tree[u]) {
		if (v != p and (w == -1 or x[v] > x[w])) {
			w = v;
		}
	}

	vector<pii> r;
	for (int v : tree[u]) {
		if (v != p and v != w) {
			map<int, int> y;
			vector<pii> z;
			dfs2(v, u, n, tree, x, s, y, z, q, res, c);
			r.insert(r.end(), all(z));
			erase(s, y, z);
		}
	}
	
	if (w != -1) {
		dfs2(w, u, n, tree, x, s, t, l, q, res, c);
	}
	add(c[u], 1, l, t, s);
	for (auto [x, k] : r) {
		add(x, k, l, t, s);
	}

	// cout << u + 1 << ": ";
	// rep(j, 0, n + 1) {
	// 	cout << s.query(j, j) << ' ';
	// }
	// cout << endl;
	for (auto [k, i] : q[u]) {
		res[i] = s.query(k, n);
	}

}

void solve() {
    int n, m;
	cin >> n >> m;

	vi c(n);
	rep(i, 0, n) {
		cin >> c[i];
	}

	vector<vi> tree(n);
	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		tree[u - 1].push_back(v - 1);
		tree[v - 1].push_back(u - 1);
	}

	vector<vector<pii>> q(n);
	rep(i, 0, m) {
		int v, k;
		cin >> v >> k;
		q[v - 1].push_back({k, i});
	}

	vi x(n, 1);
	dfs1(0, -1, tree, x);

	vi res(m);
	SegTree<int> s(n + 1, 0, [](int a, int b) {
		return a + b;
	});
	s.upd(0, n);
	map<int, int> t;
	vector<pii> l;
	dfs2(0, -1, n, tree, x, s, t, l, q, res, c);

	for (int i : res) {
		cout << i << endl;
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
