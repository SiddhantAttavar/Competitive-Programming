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
	int N = 1e5;
	vector<int> spf(N + 1);
	range(i, 0, N + 1) {
		spf[i] = i;
	}
	range(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);

		vector<int> a(n);
		arrPut(a);

		vector<int> m(x + 1, 0);
		int y = x;
		while (y != 1) {
			m[spf[y]]++;
			y /= spf[y];
		}

		vector<int> l = {1};
		range(i, 0, x + 1) {
			if (!m[i]) {
				continue;
			}

			int z = 1;
			vector<int> nl(l.begin(), l.end());
			range(j, 0, m[i]) {
				z *= i;
				for (int k : l) {
					nl.push_back(k * z);
				}
			}
			l = nl;
		}

		vector<int> p(x + 1);
		range(i, 0, l.size()) {
			p[l[i]] = i;
		}

		vector<vector<int>> dp(n + 1, vector<int>(l.size(), 0));
		range(j, 0, l.size()) {
			dp[0][j] = -1;
		}
		range(i, 0, n) {
			range(j, 0, l.size()) {
				dp[i + 1][j] = dp[i][j];
				if (l[j] % a[i]) {
					continue;
				}

				if (a[i] == l[j]) {
					dp[i + 1][j] = i;
				}
				else {
					dp[i + 1][j] = max(dp[i][j], dp[i][p[l[j] / a[i]]]);
				}
			}
		}

		SegTree<int> s(n + 1, n, [](int x, int y) {return min(x, y);});
		s.upd(0, 0);
		range(i, 0, n) {
			s.upd(i + 1, s.query(dp[i + 1][l.size() - 1] + 1, i) + 1);
		}
		print(s.query(n, n));
	}
}
