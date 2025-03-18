#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

struct SegTree {
	vector<vector<array<int, 4>>> a;

	SegTree(int n, vector<array<int, 4>> &b) {
		a = vector<vector<array<int, 4>>>(4 * n);
		build(0, n - 1, 0, b);
	}

	vector<array<int, 4>> combine(vector<array<int, 4>> &a, vector<array<int, 4>> &b) {
		vector<array<int, 4>> res;
		int x = 1e9, i = 0, j = 0;
		while (i < a.size() or j < b.size()) {
			if (j == b.size() or (i < a.size() and a[i][0] < b[j][0])) {
				x = min(x, a[i][1]);
				res.push_back({a[i][0], x, i, j - 1});
				i++;
			}
			else {
				x = min(x, b[j][1]);
				res.push_back({b[j][0], x, i - 1, j});
				j++;
			}
		}
		return res;
	}

	void build(int s, int e, int curr, vector<array<int, 4>> &b) {
		if (s == e) {
			a[curr] = {b[s]};
			return;
		}

		int mid = (s + e) / 2;
		build(s, mid, 2 * curr + 1, b);
		build(mid + 1, e, 2 * curr + 2, b);
		a[curr] = combine(a[2 * curr + 1], a[2 * curr + 2]);
	}

	int query(int l, int r, int s, int e, int curr, int k, int i) {
		if (i == -1) {
			return 1e9;
		}

		if (l > e || r < s) {
			return 1e9;
		}

		if (l <= s && r >= e) {
			return a[curr][i][1];
		}

		int mid = (s + e) / 2;
		return min(
			query(l, r, s, mid, 2 * curr + 1, k, a[curr][i][2]),
			query(l, r, mid + 1, e, 2 * curr + 2, k, a[curr][i][3])
		);
	}
};

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &l, vector<int> &d, vector<int> &x, vector<int> &y) {
	l.push_back(u);
	x[u] = l.size() - 1;
	for (int v : graph[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			dfs(v, u, graph, l, d, x, y);
		}
	}
	y[u] = l.size() - 1;
}

int32_t main() {
	setup();

	int n, r;
	input(n, r);

	vector<int> a(n);
	arrput(a);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> l;
	vector<int> d(n, 0);
	vector<int> x(n), y(n);
	dfs(r - 1, -1, graph, l, d, x, y);

	vector<array<int, 4>> b(n);
	rep(i, 0, n) {
		b[i] = {d[l[i]], a[l[i]], -1, -1};
	}

	SegTree s(n, b);

	int m;
	input(m);

	int res = 0;
	while (m--) {
		int p, q;
		input(p, q);

		int u = (p + res) % n;
		int k = (q + res) % n;

		int i = upper_bound(s.a[0].begin(), s.a[0].end(), array<int, 4>({d[u] + k, (int) 1e9, n, n})) - s.a[0].begin() - 1;
		res = s.query(x[u], y[u], 0, n - 1, 0, d[u] + k, i);
		print(res);
	}
}
