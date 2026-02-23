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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

#define ll long long
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int dfs(int u, int p, vector<vi> &graph, vector<LineContainer> &l, vi &a, vi &d, vi &dp, vi &res) {
	int o = d[u], s = a[u] * d[u];
	vi x, z;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		d[v] = o + 1;
		s += dfs(v, u, graph, l, a, d, dp, res);
		x.push_back(d[v]);
		z.push_back(v);
		d[u] = max(d[u], d[v]);
		dp[u] = max(dp[u], dp[v]);
		a[u] += a[v];
	}

	vi y = x;
	x.insert(x.begin(), 0);
	y.push_back(0);
	rep(i, 1, sz(x)) {
		x[i] = max(x[i - 1], x[i]);
	}
	for (int i = sz(y) - 2; i >= 0; i--) {
		y[i] = max(y[i], y[i + 1]);
	}

	rep(i, 0, sz(z)) {
		dp[u] = max(dp[u], l[z[i]].query(max(x[i], y[i + 1]) + 1));
	}
	for (int v : z) {
		if (sz(l[u]) < sz(l[v])) {
			swap(l[u], l[v]);
		}
		for (Line i : l[v]) {
			l[u].add(i.k, i.m);
		}
	}
	l[u].add(a[u], -a[u] * o);
	// print(u, s - o * a[u], s, o, a[u]);
	res[u] = s - o * a[u] + dp[u];
	return s;
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

		vector<LineContainer> l(n);
		vi d(n, 0), dp(n, 0), res(n, 0);
		dfs(0, -1, graph, l, a, d, dp, res);
		arrprint(res);
	}
}
