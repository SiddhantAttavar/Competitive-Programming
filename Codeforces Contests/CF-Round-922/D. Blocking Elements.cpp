#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 

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

bool check(int n, vector<int> &a, int k) {
	vector<int> pref(n + 1, 0);
	range(i, 0, n) {
		pref[i + 1] = pref[i] + a[i];
	}

	vector<int> b(n);
	range(i, 0, n) {
		int l = -1, r = i - 1;
		b[i] = i - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if ((pref[i] - pref[m + 1]) <= k) {
				b[i] = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
	}

	// print(k);
	// arrPrint(b);

	SegTree<int> s(n, 1e18, [](int a, int b) {return min(a, b);});

	vector<int> dp(n, 1e18), dp2(n, 1e18);
	range(i, 0, n) {
		if (b[i] == -1) {
			dp[i] = a[i];
		}
		else {
			dp[i] = a[i] + s.query(b[i], i - 1, 0, n - 1, 0);
		}
		s.update(i, dp[i], 0, n - 1, 0);
	}

	int x = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] <= k) {
			return true;
		}
		x += a[i];
		if (x > k) {
			break;
		}
	}

	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);


		int l = 0, r = 1e18, res = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(n, a, m)) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		print(res);
	}
}
