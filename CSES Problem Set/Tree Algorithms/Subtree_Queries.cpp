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
	vector<int> a;
	int id;

	int (*combine) (int, int);

	SegTree(int n, int i, int func(int, int)) {
		id = i;
		combine = func;
		a = vector<int>(4 * n, id);
	}

	int query(int l, int r, int s, int e, int curr) {
		if (l > e || r < s) {
			return id;
		}

		if (l <= s && r >= e) {
			return a[curr];
		}

		int mid = (s + e) / 2;
		return combine(
			query(l, r, s, mid, 2 * curr + 1),
			query(l, r, mid + 1, e, 2 * curr + 2)
		);
	}

	void update(int i, int x, int s, int e, int curr) {
		if (s > i || e < i) {
			return;
		}

		if (s == e) {
			a[curr] = x;
			return;
		}

		int mid = (s + e) / 2;

		update(i, x, s, mid, 2 * curr + 1);
		update(i, x, mid + 1, e, 2 * curr + 2);

		a[curr] = combine(a[2 * curr + 1], a[2 * curr + 2]);
	}
};

void dfs(int u, int w, vector<vector<int>> &graph, vector<int> &l, vector<int> &p, vector<int> &q) {
	l.push_back(u);
	p[u] = l.size() - 1;
	for (int v : graph[u]) {
		if (v != w) {
			dfs(v, u, graph, l, p, q);
		}
	}
	q[u] = l.size() - 1;
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> v(n);
	arrput(v);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> l, a(n), b(n);
	dfs(0, -1, graph, l, a, b);

	vector<int> k(n);
	rep(i, 0, n) {
		k[l[i]] = i;
	}

	SegTree s(n, 0, [](int x, int y) {
		return x + y;
	});
	rep(i, 0, n) {
		s.update(k[i], v[i], 0, n - 1, 0);
	}

	while (q--) {
		int o, u;
		input(o, u);
		u--;

		if (o == 1) {
			int x;
			input(x);
			s.update(k[u], x, 0, n - 1, 0);
		}
		else {
			print(s.query(a[u], b[u], 0, n - 1, 0));
		}
	}
}
