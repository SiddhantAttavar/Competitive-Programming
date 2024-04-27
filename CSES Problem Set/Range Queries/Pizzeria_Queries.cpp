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

template<typename T> struct SegTree {
	vector<T> a;
	T id;
	T (*combine)(T, T);

	SegTree(int n, T _id, T cmb(T, T)) {
		id = _id;
		combine = cmb;
		a.resize(4 * n, id);
	}

	T query(int l, int r, int s, int e, int c) {
		if (e < l or r < s) {
			return id;
		}

		if (s <= l and r <= e) {
			return a[c];
		}

		int m = (l + r) / 2;
		return combine(
			query(l, m, s, e, 2 * c + 1),
			query(m + 1, r, s, e, 2 * c + 2)
		);
	}

	void update(int l, int r, int i, T x, int c) {
		if (i < l or r < i) {
			return;
		}

		if (l == r) {
			a[c] = x;
			return;
		}

		int m = (l + r) / 2;
		update(l, m, i, x, 2 * c + 1);
		update(m + 1, r, i, x, 2 * c + 2);
		a[c] = combine(a[2 * c + 1], a[2 * c + 2]);
	}
};

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrPut(a);

	SegTree<pair<int, int>> s(n, {1e10, 1e10}, [](pair<int, int> a, pair<int, int> b) {
		return make_pair(min(a.first, b.first), min(a.second, b.second));
	});
	range(i, 0, n) {
		s.update(0, n - 1, i, {a[i] + i, a[i] + n - i - 1}, 0);
	}

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int i, x;
			input(i, x);
			s.update(0, n - 1, i - 1, {x + i - 1, x + n - i}, 0);
		}
		else {
			int i;
			input(i);
			print(min(
				s.query(0, n - 1, 0, i - 1, 0).second - (n - i),
				s.query(0, n - 1, i - 1, n - 1, 0).first - (i - 1)
			));
		}
	}
}
