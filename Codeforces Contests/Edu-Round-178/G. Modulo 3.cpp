#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

const int N = 2e5;
vector<pair<int, int>> seg[4 * N];

struct DSU {
	vector<int*> k;
	vector<int> a, e, v;
	vector<pair<int, int>> s;
	DSU(int n) : a(n, -1), e(n, 0) {}
	void assign(int &x, int y) {
		k.push_back(&x);
		v.push_back(x);
		x = y;
	}
	int time() {
		return v.size();
	}
	void rollback(int t) {
		while (v.size() > t) {
			*k.back() = v.back();
			k.pop_back();
			v.pop_back();
		}
	}
	pair<int, int> get(int x) {
		if (a[x] < 0) {
			return {x, 0};
		}
		pair<int, int> p = get(a[x]);
		return {p.first, p.second ^ e[x]};
	}
	int unite(int x, int y) {
		int p, q;
		tie(x, p) = get(x);
		tie(y, q) = get(y);
		if (x == y) {
			return p ^ q;
		}
		if (a[x] > a[y]) {
			swap(x, y);
		}
		assign(a[x], a[x] + a[y]);
		assign(a[y], x);
		assign(e[y], p ^ q ^ 1);
		return 0;
	}
};

void insert(int s, int e, int u, int v, int l = 0, int r = N - 1, int c = 1) {
	if (l > e or r < s) {
		return;
	}
	if (s <= l and r <= e) {
		seg[c].push_back({u, v});
		return;
	}
	int m = (l + r) / 2;
	insert(s, e, u, v, l, m, 2 * c);
	insert(s, e, u, v, m + 1, r, 2 * c + 1);
}

void dfs(DSU &d, vector<bool> &res, int x, int l = 0, int r = N - 1, int c = 1) {
	if (l >= res.size()) {
		return;
	}
	int t = d.time();
	for (pair<int, int> p : seg[c]) {
		x ^= d.unite(p.first, p.second);
	}
	if (l == r) {
		res[l] = x;
		d.rollback(t);
		return;
	}
	int m = (l + r) / 2;
	dfs(d, res, x, l, m, 2 * c);
	dfs(d, res, x, m + 1, r, 2 * c + 1);
	d.rollback(t);
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> g(n);
	arrput(g);

	vector<vector<pair<int, int>>> m(n);
	rep(i, 0, n) {
		m[i].push_back({g[i] - 1, 0});
	}

	vector<int> k(q);
	rep(i, 0, q) {
		int x, y;
		input(x, y, k[i]);
		m[x - 1].push_back({y - 1, i});
	}

	rep(i, 0, n) {
		m[i].push_back({-1, q});
		rep(j, 0, m[i].size() - 1) {
			insert(m[i][j].second, m[i][j + 1].second - 1, i, m[i][j].first);
		}
	}

	vector<bool> res(q);
	DSU d(n);
	dfs(d, res, n % 2);

	rep(i, 0, q) {
		if (k[i] % 3 <= 1) {
			print(k[i] % 3);
		}
		else if (res[i] % 2 == 0) {
			print(1);
		}
		else {
			print(2);
		}
	}
}
