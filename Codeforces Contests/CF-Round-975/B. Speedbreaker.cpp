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
const int MOD = (int) 1e9 + 7; //998244353

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
	int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
		if (r < lo || val > seg[ind]) return -1;
		if (l == r) return l;
		int m = (l+r)/2;
		int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
		return first_at_least(lo,val,2*ind+1,m+1,r);
	}
};

bool check(vector<vector<int>> &p, vector<vector<int>> &q) {
	int n = p.size();
	SegTree<int> s(n, -1, [](int a, int b) {
		return max(a, b);
	});

	range(i, 0, n) {
		for (int j : q[i]) {
			if (s.query(0, j - 1) >= j) {
				return false;
			}
		}

		for (int j : p[i]) {
			s.upd(j, i);
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<pair<int, int>> b(n);
		range(i, 0, n) {
			b[i] = {
				max(0ll, i - a[i] + 1),
				min(n - 1, i + a[i] - 1),
			};
		}

		vector<vector<int>> p(n), q(n);
		range(i, 0, n) {
			q[i].push_back(b[i].first);
			p[b[i].second].push_back(i);
		}

		if (!check(p, q)) {
			print(0);
			continue;
		}

		int l = 0, r = n - 1;
		range(i, 0, n) {
			l = max(l, b[i].first);
			r = min(r, b[i].second);
		}

		print(max(0ll, r - l + 1));
	}
}
