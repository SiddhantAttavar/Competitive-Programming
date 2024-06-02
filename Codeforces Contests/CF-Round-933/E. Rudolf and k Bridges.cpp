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
const int MOD = (int) 1e9 + 7;

template<class T> struct SegTree {
	vector<T> a;
	T id;
	T (*combine) (T, T);
	SegTree(int n, T i, T func(T, T)) {
		id = i; combine = func;
		a = vector<T>(4 * n, id);
	}
	T query(int l, int r, int s, int e, int curr) {
		if (l > e || r < s)  return id;
		if (l <= s && r >= e) return a[curr];
		int mid = (s + e) / 2;
		return combine(query(l, r, s, mid, 2 * curr + 1),
			query(l, r, mid + 1, e, 2 * curr + 2));
	}
	void update(int i, T x, int s, int e, int curr) {
		if (s > i || e < i) return;
		if (s == e) { a[curr] = x; return; }
		int mid = (s + e) / 2;
		update(i, x, s, mid, 2 * curr + 1);
		update(i, x, mid + 1, e, 2 * curr + 2);
		a[curr] = combine(a[2 * curr + 1], a[2 * curr + 2]);
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k, d;
		input(n, m, k, d);

		vector<vector<int>> a(n, vector<int>(m));
		range(i, 0, n) {
			arrPut(a[i]);
		}

		vector<SegTree<int>> dp(n, SegTree<int>(m, 1e15, [](int x, int y) {
			return min(x, y);
		}));
		range(i, 0, n) {
			dp[i].update(0, 1, 0, m, 0);
			range(j, 1, m) {
				int x = dp[i].query(max(0ll, j - d - 1), j - 1, 0, m - 1, 0);
				dp[i].update(j, x + a[i][j] + 1, 0, m - 1, 0);
			}
		}

		int c = 0;
		range(i, 0, k) {
			c += dp[i].query(m - 1, m - 1, 0, m - 1, 0);
		}
		int res = c;
		range(i, k, n) {
			c += dp[i].query(m - 1, m - 1, 0, m - 1, 0) - dp[i - k].query(m - 1, m - 1, 0, m - 1, 0);
			res = min(res, c);
		}
		
		print(res);
	}
}
