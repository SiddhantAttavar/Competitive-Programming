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
	int first(int ind, int l, int r) { // if seg stores max across range
		if (l == r) return l;
		int m = (l+r)/2;
		if (seg[2 * ind][3] == 0) {
			return first(2 * ind + 1, m + 1, r);
		}
		return first(2 * ind, l, m);
	}
	int last(int ind, int l, int r) { // if seg stores max across range
		if (l == r) return l;
		int m = (l+r)/2;
		if (seg[2 * ind + 1][4] == 0) {
			return first(2 * ind, l, m);
		}
		return first(2 * ind + 1, m + 1, r);
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		SegTree<vector<int>> s(n, {0, (int) 1e9, 0, 0, 0}, [](vector<int> a, vector<int> b) {
			return vector<int>{
				a[0] + b[0],
				min(a[1], b[1]),
				max(a[2], b[2]),
				a[3] + b[3],
				a[4] + b[4]
			};
		});

		vector<int> pref(n, a[0]), suff(n, a[n - 1]);
		range(i, 1, n) {
			pref[i] = max(pref[i - 1], a[i]);
		}
		for (int i = n - 2; i >= 0; i--) {
			suff[i] = min(suff[i + 1], a[i]);
		}

		range(i, 0, n) {
			s.upd(i, {
				a[i],
				a[i],
				a[i],
				i > 0 and a[i] < pref[i - 1],
				i < n - 1 and a[i] > suff[i + 1],
			});
		}

		if (s.query(0, n - 1)[3] == 0) {
			print(-1, -1);
		}
		else {
			int l = s.first(0, 0, n - 1), r = s.last(0, 0, n - 1);
			if (l == r + 1) {
				print(r, l);
			}
			r++;
			l--;
			vector<int> v = s.query(l, r);

			int l1 = 0, r1 = n - 1, res1 = 0;
			while (l1 <= r1) {
				int m = (l1 + r1) / 2;
				if (s.query(0, m)[2] > v[1]) {
					r1 = m - 1;
				}
				else {
					res1 = m + 1;
					l1 = m + 1;
				}
			}

			int l2 = 0, r2 = n - 2, res2 = n - 1;
			while (l2 <= r2) {
				int m = (l2 + r2) / 2;
				if (s.query(m, n - 1)[1] < v[2]) {
					l2 = m + 1;
				}
				else {
					res2 = m - 1;
					r2 = m - 1;
				}
			}

			print(res2 - 1, res1 + 1);
		}

		int q;
		input(q);
		while (q--) {
			int i, x;
			input(i, x);
			i--;

			a[i] = x;

			s.upd(i, {
				a[i],
				a[i],
				a[i],
				i > 0 and a[i] < s.query(0, i - 1)[1],
				i < n - 1 and a[i] > s.query(i + 1, n - 1)[2]
			});

			if (s.query(0, n - 1)[3] == 0) {
				print(-1, -1);
				continue;
			}

			int l = s.first(0, 0, n - 1), r = s.last(0, 0, n - 1);
			if (l == r + 1) {
				print(r - 1, l - 1);
			}
			r++;
			l--;
			vector<int> v = s.query(l, r);

			int l1 = 0, r1 = n - 1, res1 = 0;
			while (l1 <= r1) {
				int m = (l1 + r1) / 2;
				if (s.query(0, m)[2] > v[1]) {
					r1 = m - 1;
				}
				else {
					res1 = m + 1;
					l1 = m + 1;
				}
			}

			int l2 = 0, r2 = n - 2, res2 = n - 1;
			while (l2 <= r2) {
				int m = (l2 + r2) / 2;
				if (s.query(m, n - 1)[1] < v[2]) {
					l2 = m + 1;
				}
				else {
					res2 = m - 1;
					r2 = m - 1;
				}
			}

			print(res2 - 1, res1 + 1);
		}
	}
}
