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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

template<typename T> struct SegTree {
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
};

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	string s;
	input(s);

	vector<int> a(n);
	arrput(a);

	vector<int> p(n + 1, 0);
	rep(i, 0, n) {
		p[i + 1] = p[i] + a[i];
	}

	vector<int> l(n + 1, -1);
	rep(i, 0, n) {
		if (s[i] == '1') {
			l[i + 1] = i;
		}
		else {
			l[i + 1] = l[i];
		}
	}

	SegTree<int> t(n + 1, 0, [](int a, int b) {
		return max(a, b);
	});

	vector<int> dp(n + 1, 0), m(n + 1, 0);
	rep(i, 0, n) {
		int x = p[min(n, i + k)];
		if (l[i + 1] < 0) {
			m[i + 1] = m[i];
			continue;
		}
		dp[i + 1] = max(x - p[i], x + t.query(max(1ll, i + k), l[i + 1] + 1));
		if (min(i - k + 1, l[i + 1]) > 0) {
			dp[i + 1] = max(dp[i + 1], x + m[min(i - k + 1, l[i + 1])] - p[i]);
		}
		t.upd(i + 1, dp[i + 1] - x);
		m[i + 1] = max(m[i], dp[i]);
	}
	print(p[n] - m[n]);
}
