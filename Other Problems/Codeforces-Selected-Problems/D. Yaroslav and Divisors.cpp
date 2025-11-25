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

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T a, T b);
	int n; vector<T> seg;
	SegTree(int _n, T id, T _cmb(T, T)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
	/// int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
	/// 	if (r < lo || val > seg[ind]) return -1;
	/// 	if (l == r) return l;
	/// 	int m = (l+r)/2;
	/// 	int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
	/// 	return first_at_least(lo,val,2*ind+1,m+1,r);
	/// }
};

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> p(n);
	arrput(p);

	vector<int> a(n + 1, -1);
	rep(i, 0, n) {
		a[p[i]] = i;
	}

	vector<vector<pair<int, int>>> s(n), t(n);
	rep(i, 0, m) {
		int l, r;
		input(l, r);
		if (l - 2 >= 0) {
			s[l - 2].push_back({r - 1, i});
		}
		t[r - 1].push_back({l - 1, i});
	}

	SegTree<int> seg(n, 0, [](int a, int b) {
		return a + b;
	});
	vector<int> v(n + 1, 0);
	vector<int> res(m, 0);
	rep(r, 0, n) {
		for (int x = p[r]; x <= n; x += p[r]) {
			v[x]++;
			seg.upd(a[x], v[x]);
		}
		for (auto [l, i] : s[r]) {
			res[i] -= seg.query(r + 1, l);
		}
		for (auto [l, i] : t[r]) {
			res[i] += seg.query(l, r);
		}
	}
	for (int i : res) {
		print(i);
	}
}
