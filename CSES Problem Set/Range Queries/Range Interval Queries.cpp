#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

vector<int> seg[1 << 19];

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T &a, T &b);
	int n;
	SegTree(int _n, T id, T _cmb(T&, T&)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	int query(int l, int r, int a, int b) {	// zero-indexed, inclusive
		int res = 0;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) {
				res += upper_bound(seg[l].begin(), seg[l].end(), b) - lower_bound(seg[l].begin(), seg[l].end(), a);
				l++;
			}
			if (r&1) {
				--r;
				res += upper_bound(seg[r].begin(), seg[r].end(), b) - lower_bound(seg[r].begin(), seg[r].end(), a);
			}
		}
		return res;
	}
};

SegTree<vector<int>> s(1 << 18, {}, [](vector<int> &a, vector<int> &b) {
	vector<int> res(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
	return res;
});

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrput(a);

	rep(i, 0, n) {
		seg[i + (1 << 18)] = {a[i]};
	}
	for (int i = s.n - 1; i >= 0; i--) {
		s.pull(i);
	}

	while (q--) {
		int a, b, c, d;
		input(a, b, c, d);
		print(s.query(a - 1, b - 1, c, d));
	}
}
