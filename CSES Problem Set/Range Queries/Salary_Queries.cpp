#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

template<typename T, int SZ> struct SparseSegmentTree {
	vector<pair<int, int>> tree;
	vector<T> seg; T id; int n;
	T (*cmb) (T, T);
	SparseSegmentTree(T _id, T _cmb(T, T), int q = 0):id(_id),
		cmb(_cmb),n(1),tree({{-1, -1}}),seg({{id}}) {
		int k = 2 * q * __lg(SZ);
		tree.reserve(k); seg.reserve(k);
	}
	void add(int c, int l, int r) {
		if (tree[c].first != -1 or l == r) return;
		tree[c] = {n, n + 1}; n += 2;
		tree.push_back({-1, -1}); tree.push_back({-1, -1});
		seg.push_back(id); seg.push_back(id);
	}
	T query(int l, int r, int s=0, int e=SZ-1, int c=0) {
		if (l > e || r < s) return id;
		if (l <= s && r >= e) return seg[c];
		int mid = (s + e) / 2; add(c, s, e);
		return cmb(query(l,r, s, mid, tree[c].first),
			query(l, r, mid + 1, e, tree[c].second));
	}
	void upd(int i, T x, int s=0, int e=SZ-1, int c=0) {
		if (s > i || e < i) return;
		if (s == e) {seg[c] = x; return;}
		int mid = (s + e) / 2; add(c, s, e);
		upd(i, x, s, mid, tree[c].first);
		upd(i, x, mid + 1, e, tree[c].second);
		seg[c] = cmb(seg[tree[c].first], seg[tree[c].second]);
	}
};

const int N = 1e9;

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	SparseSegmentTree<int, 1ll << 30> seg(0, [](int a, int b) {
		return a + b;
	}, n + 2 * q);
	map<int, int> m;
	for (int p : a) {
		m[p]++;
		seg.upd(p, m[p]);
	}

	while (q--) {
		char c;
		input(c);

		if (c == '!') {
			int i, x;
			input(i, x);

			i--;
			m[a[i]]--;
			seg.upd(a[i], m[a[i]]);

			a[i] = x;
			m[a[i]]++;
			seg.upd(a[i], m[a[i]]);
		}
		else {
			int l, r;
			input(l, r);

			print(seg.query(l, r));
		}
	}
}
