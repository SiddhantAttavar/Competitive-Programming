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
const int MOD = (int) 1e9 + 7;

template<class T> struct SegTree {
	vector<T> a;
	T id;
	T (*combine) (T, T);
	SegTree(int n, T i, T func(T, T)) {
		id = i; combine = func;
		a = vector<T>(4 * n, id);
	}
	int query(int l, int r, int x, int s, int e, int curr) {
		if (l > e || r < s)  return 0;
		if (l <= s && r >= e) return a[curr].p[upper_bound(a[curr].a.begin(), a[curr].a.end(), x) - a[curr].a.begin()];
		int mid = (s + e) / 2;
		return (query(l, r, x, s, mid, 2 * curr + 1) +
			query(l, r, x, mid + 1, e, 2 * curr + 2));
	}
	void build(int l, int r, int curr, vector<T> arr) {
		if (l == r) {
			a[curr] = arr[l];
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, 2 * curr + 1, arr);
		build(mid + 1, r, 2 * curr + 2, arr);
		a[curr] = combine(a[2 * curr + 1], a[2 * curr + 2]);
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

struct Node {
	vector<int> a;
	vector<int> p;
};

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	SegTree<Node> s(n, Node {{}, {0}}, [](Node a, Node b) {
		vector<int> v;
		int i = 0, j = 0;
		while (i < (int) a.a.size() or j < (int) b.a.size()) {
			if (i == (int) a.a.size() or (j < (int) b.a.size() and a.a[i] > b.a[j])) {
				v.push_back(b.a[j]);
				j++;
			}
			else {
				v.push_back(a.a[i]);
				i++;
			}
		}

		vector<int> p(v.size() + 1, 0);
		range(i, 0, (int) v.size()) {
			p[i + 1] = p[i] + v[i];
		}

		return Node {v, p};
	});


	vector<Node> b(n);
	range(i, 0, n) {
		b[i] = Node {{a[i]}, {0, a[i]}};
	}
	s.build(0, n - 1, 0, b);

	// range(i, 0, 4 * n) {
	// 	arrPrint(s.a[i].a);
	// 	arrPrint(s.a[i].p);
	// }
	// print("");

	int x = 0;
	int q;
	input(q);
	while (q--) {
		int a, b, c;
		input(a, b, c);

		a ^= x;
		b ^= x;
		c ^= x;

		x = s.query(a - 1, b - 1, c, 0, n - 1, 0);
		print(x);
	}
}
