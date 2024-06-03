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
		int n;
		input(n);

		vector<int> x(n), y(n);
		range(i, 0, n) {
			input(x[i], y[i]);
		}

		vector<int> w(n, 0), a(n, 29);
		range(i, 0, n) {
			while (a[i] >= 0 and (x[i] & (1 << a[i])) == (y[i] & (1 << a[i]))) {
				w[i] |= x[i] & (1 << a[i]);
				a[i]--;
			}
		}

		vector<vector<int>> pref(30, vector<int>(n + 1, 0));
		range(i, 0, n) {
			range(j, 0, 30) {
				pref[j][i + 1] = pref[j][i] + ((y[i] - w[i]) >> j & 1);
			}
		}

		SegTree<int> s(n, 0, [](int x, int y) {return x | y;});
		range(i, 0, n) {
			s.update(i, w[i], 0, n - 1, 0);
		}

		int q;
		input(q);
		while (q--) {
			int l, r;
			input(l, r);

			l--;
			r--;

			int res = s.query(l, r, 0, n - 1, 0);
			for (int i = 29; i >= 0; i--) {
				int x = pref[i][r + 1] - pref[i][l] + (res >> i & 1);
				if (x > 1) {
					res |= (2 << i) - 1;
					break;
				}
				if (x == 1) {
					res |= 1 << i;
				}
			}

			cout << res << ' ';
		}
		cout << endl;
	}
}
