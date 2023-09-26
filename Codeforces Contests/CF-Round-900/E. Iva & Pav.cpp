#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

struct SegTree {
	vector<int> a;

	SegTree(int n) {
		a.resize(4 * n, -1);
	}

	void update(int i, int x, int l, int r, int u) {
		if (l > i or r < i) {
			return;
		}

		if (l == r) {
			a[u] = x;
			return;
		}

		int m = (l + r) / 2;
		update(i, x, l, m, 2 * u + 1);
		update(i, x, m + 1, r, 2 * u + 2);

		if (a[2 * u + 1] == -1) {
			a[u] = a[2 * u + 2];
		}
		else if (a[2 * u + 2] == -1) {
			a[u] = a[2 * u + 1];
		}
		else {
			a[u] = a[2 * u + 1] & a[2 * u + 2];
		}
	}

	int query(int x, int y, int l, int r, int u) {
		// print('d', x, y, l, r, u);
		if (l > y or r < x) {
			return -1;
		}

		if (x <= l and r <= y) {
			return a[u];
		}

		int m = (l + r) / 2;
		int p = query(x, y, l, m, 2 * u + 1);
		int q = query(x, y, m + 1, r, 2 * u + 2);

		if (p == -1) {
			return q;
		}
		else if (q == -1) {
			return p;
		}
		
		return p & q;
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		SegTree s(n);
		range(i, 0, n) {
			s.update(i, a[i], 0, n - 1, 0);
			// arrPrint(s.a);
		}

		// arrPrint(s.a);

		int q;
		input(q);
		while (q--) {
			int i, k;
			input(i, k);
			i--;

			int l = i, r = n - 1, res = -2;
			while (l <= r) {
				int m = (l + r) / 2;
				// print(i, k, m, s.query(i, m, 0, n - 1, 0));
				if (s.query(i, m, 0, n - 1, 0) >= k) {
					res = m;
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}

			cout << res + 1 << ' ';
		}

		// print("");
		print("");
	}
}
