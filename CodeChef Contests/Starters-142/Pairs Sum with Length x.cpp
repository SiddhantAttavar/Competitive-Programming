#include <bits/stdc++.h>
#include <climits>
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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);
		
		int y = 1;
		range(i, 0, x - 1) {
			y *= 10;
		}

		vector<int> a(n);
		arrPut(a);

		vector<pair<int, int>> v(n);
		range(i, 0, n) {
			v[i] = {a[i], i};
		}
		sort(v.begin(), v.end());

		vector<int> ind(n), b(n);
		range(i, 0, n) {
			b[i] = v[i].first;
			ind[v[i].second] = i;
		}

		SegTree<int> s(n, 0, [](int x, int y) {return x + y;});

		int res = 0;
		range(i, 0, n) {
			int l = lower_bound(b.begin(), b.end(), y - a[i]) - b.begin();
			int r = lower_bound(b.begin(), b.end(), x == 19 ? LONG_MAX - a[i] : y * 10 - a[i]) - b.begin() - 1;
			if (l <= r) {
				res += s.query(l, r) * (n - i);
			}
			s.upd(ind[i], i + 1);
		}

		print(res);
	}
}
