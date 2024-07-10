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

template<class T> struct SegTree { // cmb(ID,b) = b
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


int solve(int l, int r, vector<int> &a, SegTree<pair<int, int>> &s) {
	if (l >= r) {
		return 0;
	}

	pair<int, int> p = s.query(l, r);
	while (l < r and p.second == l) {
		l++;
		p = s.query(l, r);
	}

	if (l == r) {
		return 0;
	}

	pair<int, int> q = s.query(l, p.second - 1);
	if (p.first != q.first) {
		return solve(l, p.second - 1, a, s) + solve(p.second + 1, r, a, s);
	}

	return solve(l, p.second - 1, a, s) + solve(p.second + 1, r, a, s) + (q.second - l + 1) * (r - p.second + 1);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		SegTree<pair<int, int>> s(n, {0, 0}, [](pair<int, int> x, pair<int, int> y) {
			if (x.first > y.first) {
				return x;
			}
			return y;
		});

		range(i, 0, n) {
			s.upd(i, {a[i], i});
		}

		int q;
		input(q);
		while (q--) {
			int k;
			input(k);

			print(solve(0, n - k - 1, a, s));
		}
	}
}
