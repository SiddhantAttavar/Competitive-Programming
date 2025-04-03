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

struct SegTree {
	vector<int> a;

	SegTree(vector<int> arr) {
		a.resize(4 * arr.size(), 1e9);
		range(i, 0, arr.size()) {
			update(0, 0, arr.size() - 1, i, arr[i]);
		}
	}

	void update(int u, int l, int r, int i, int x) {
		if (r < i or l > i) {
			return;
		}

		if (l == r) {
			a[u] = x;
			return;
		}

		int m = (l + r) / 2;
		update(2 * u + 1, l, m, i, x);
		update(2 * u + 2, m + 1, r, i, x);
		a[u] = min(a[2 * u + 1], a[2 * u + 2]);
	}

	int query(int u, int l, int r, int s, int e) {
		if (s <= l and r <= e) {
			return a[u];
		}

		if (r < s or l > e) {
			return 1e9;
		}

		int m = (l + r) / 2;
		return min(query(2 * u + 1, l, m, s, e), query(2 * u + 2, m + 1, r, s, e));
	}
};

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> a(n);
	arrPut(a);

	SegTree segTree(a);

	while (m--) {
		int o;
		input(o);
		
		if (o == 1) {
			int i, x;
			input(i, x);
			segTree.update(0, 0, n - 1, i, x);
		}
		else {
			int l, r;
			input(l, r);

			print(segTree.query(0, 0, n - 1, l, r - 1));
		}
	}
}
