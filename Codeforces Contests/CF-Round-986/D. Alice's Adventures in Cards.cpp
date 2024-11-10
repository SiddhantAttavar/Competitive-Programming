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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

struct SegTree {
	vector<int> a, b;
	int id;

	int (*combine) (int, int);

	SegTree(int n, int i, int func(int, int)) {
		id = i;
		combine = func;
		a = vector<int>(4 * n, id);
		b = vector<int>(4 * n, 4 * n);
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

	int find(int l, int r, int s, int e, int curr) {
		if (l > e || r < s) {
			return b.size();
		}

		if (l <= s && r >= e) {
			return b[curr];
		}

		int mid = (s + e) / 2;
		return min(
			find(l, r, s, mid, 2 * curr + 1),
			find(l, r, mid + 1, e, 2 * curr + 2)
		);
	}

	void update(int i, int x, int s, int e, int curr) {
		if (s > i || e < i) {
			return;
		}

		if (s == e) {
			b[curr] = i;
			a[curr] = x;
			return;
		}

		int mid = (s + e) / 2;

		update(i, x, s, mid, 2 * curr + 1);
		update(i, x, mid + 1, e, 2 * curr + 2);

		a[curr] = combine(a[2 * curr + 1], a[2 * curr + 2]);
		b[curr] = min(b[2 * curr + 1], b[2 * curr + 2]);
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), b(n), c(n);
		arrPut(a);
		arrPut(b);
		arrPut(c);

		vector<int> p(n), q(n), r(n);
		range(i, 0, n) {
			a[i]--;
			b[i]--;
			c[i]--;

			p[a[i]] = i;
			q[b[i]] = i;
			r[c[i]] = i;
		}

		vector<pair<int, int>> dp(n, {-1, -1});
		SegTree x(n, 0, [](int a, int b) {return a + b;});
		SegTree y(n, 0, [](int a, int b) {return a + b;});
		SegTree z(n, 0, [](int a, int b) {return a + b;});

		x.update(a[0], 1, 0, n - 1, 0);
		y.update(b[0], 1, 0, n - 1, 0);
		z.update(c[0], 1, 0, n - 1, 0);

		range(i, 1, n) {
			if (x.query(a[i], n - 1, 0, n - 1, 0)) {
				dp[i] = {x.find(a[i], n - 1, 0, n - 1, 0), 0};
			}
			else if (y.query(b[i], n - 1, 0, n - 1, 0)) {
				dp[i] = {y.find(b[i], n - 1, 0, n - 1, 0), 1};
			}
			else if (z.query(c[i], n - 1, 0, n - 1, 0)) {
				dp[i] = {z.find(c[i], n - 1, 0, n - 1, 0), 2};
			}

			if (dp[i].first != -1) {
				x.update(a[i], 1, 0, n - 1, 0);
				y.update(b[i], 1, 0, n - 1, 0);
				z.update(c[i], 1, 0, n - 1, 0);
			}

			// arrPrint(x.b);
			// print(i, dp[i].first, dp[i].second, a[i]);
		}

		if (dp[n - 1].first == -1) {
			print("NO");
			continue;
		}

		// for (pair<int, int> p : dp) {
		// 	print(p.first, p.second);
		// }

		print("YES");

		int u = n - 1;
		vector<pair<int, int>> res;
		while (u) {
			if (dp[u].second == 0) {
				res.push_back({0, u});
				u = p[dp[u].first];
			}
			else if (dp[u].second == 1) {
				res.push_back({1, u});
				u = q[dp[u].first];
			}
			else if (dp[u].second == 2) {
				res.push_back({2, u});
				u = r[dp[u].first];
			}
		}

		print(res.size());
		reverse(res.begin(), res.end());
		string s = "qkj";
		for (pair<int, int> p : res) {
			print(s[p.first], p.second + 1);
		}
	}
}
