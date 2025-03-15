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
};

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> o(m);
	arrput(o);

	vector<vector<int>> x(n);
	rep(i, 0, m) {
		x[o[i] - 1].push_back(i);
	}

	vector<int> p(n);
	arrput(p);

	int k;
	input(k);
	vector<int> l(k), r(k), a(k);
	rep(i, 0, k) {
		input(l[i], r[i], a[i]);
		l[i]--;
		r[i]--;
	}

	vector<int> s(n, 1), e(n, k), res(n, -1);
	int h = 21;
	rep(i, 0, h) {
		vector<pair<int, int>> v;
		rep(j, 0, n) {
			if (s[j] <= e[j]) {
				v.push_back({(s[j] + e[j]) / 2, j});
			}
		}

		sort(v.begin(), v.end());
		int j = -1;
		SegTree<int> t(m + 1, 0, [](int x, int y) {
			return x + y;
		});
		vector<int> b(m + 1);
		for (pair<int, int> k : v) {
			while (j < k.first - 1) {
				j++;

				if (l[j] <= r[j]) {
					b[l[j]] += a[j];
					t.upd(l[j], b[l[j]]);
					b[r[j] + 1] -= a[j];
					t.upd(r[j] + 1, b[r[j] + 1]);
				}
				else {
					b[l[j]] += a[j];
					t.upd(l[j], b[l[j]]);
					b[m] -= a[j];
					t.upd(m, b[m]);

					b[0] += a[j];
					t.upd(0, b[0]);
					b[r[j] + 1] -= a[j];
					t.upd(r[j] + 1, b[r[j] + 1]);
				}
			}

			int y = 0;
			for (int u : x[k.second]) {
				y += t.query(0, u);
			}

			if (y >= p[k.second]) {
				e[k.second] = k.first - 1;
				res[k.second] = k.first;
			}
			else {
				s[k.second] = k.first + 1;
			}
		}
	}

	for (int i : res) {
		if (i == -1) {
			print("NIE");
		}
		else {
			print(i);
		}
	}
}
