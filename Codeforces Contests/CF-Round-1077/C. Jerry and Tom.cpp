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
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set __gnu_pbds::tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
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
		p += n;
		seg[p].first += val.first;
		seg[p].second += val.second;
		for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

void dfs1(int u, vector<vi> &tree, vi &s) {
	for (int v : tree[u]) {
		dfs1(v, tree, s);
		s[u] += s[v];
	}
}

int dfs2(int u, vector<vi> &tree, vi &d, vi &s, vector<multiset<int>> &l, SegTree<pii> &seg, bool keep) {
	int w = -1, res = 0, n = sz(d);
	for (int v : tree[u]) {
		if (w == -1 or s[v] > s[w]) {
			w = v;
		}
	}
	for (int v : tree[u]) {
		if (v != w) {
			res += dfs2(v, tree, d, s, l, seg, false);
		}
	}
	if (w != -1) {
		res += dfs2(w, tree, d, s, l, seg, true);
		swap(l[u], l[w]);
	}

	for (int v : tree[u]) {
		if (v == w) {
			continue;
		}
		for (int i : l[v]) {
			pii p = seg.query(0, d[i]), q = seg.query(d[i], n);
			res += p.first - d[u] * p.second;
			res += (d[i] - d[u]) * q.second;
			l[u].insert(i);
		}
		for (int i : l[v]) {
			seg.upd(d[i], {d[i], 1});
		}
	}

	seg.upd(d[u], {d[u], 1});
	l[u].insert(u);
	if (keep) {
		return res;
	}

	for (int i : l[u]) {
		seg.upd(d[i], {-d[i], -1});
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vi> graph(n);
		rep(i, 0, m) {
			int u, v;
			input(u, v);
			graph[v - 1].push_back(u - 1);
		}
		for (int i = n - 1; i > 0; i--) {
			graph[i].push_back(i - 1);
		}

		int c = 0, p = -1;
		vi d(n, -1);
		queue<int> q;
		q.push(n - 1);
		d[n - 1] = 0;

		vector<vi> tree(n);
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : graph[u]) {
				if (d[v] == -1) {
					tree[u].push_back(v);
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}

		vi s(n, 1);
		dfs1(n - 1, tree, s);

		SegTree<pii> seg(n + 1, {0, 0}, [](pii a, pii b) -> pii {
			return {a.first + b.first, a.second + b.second};
		});
		vector<multiset<int>> l(n);
		print(dfs2(n - 1, tree, d, s, l, seg, false));
	}
}
