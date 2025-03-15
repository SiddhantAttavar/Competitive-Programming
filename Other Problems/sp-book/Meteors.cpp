#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define ll long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;
 
const int N = 3e5;
ll seg[4 * (N + 1)];
template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID = 0;
	int n;
	SegTree(int _n) {
		for (n = 1; n < _n; ) n *= 2; 
	}
	void upd(int p, T val) { // set val at position p
		seg[p += n] += val; for (p /= 2; p; p /= 2) seg[p] = (seg[2*p]+seg[2*p+1]); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = (ra+seg[l++]);
			if (r&1) rb = (seg[--r]+rb);
		}
		return (ra+rb);
	}
};


vector<int> x[N];
int p[N];
int l[N], r[N], a[N];
int s[N], e[N], res[N];
 
int32_t main() {
	setup();
 
	int n, m;
	input(n, m);
 
	rep(i, 0, m) {
		int j;
		input(j);
		x[j - 1].push_back(i);
	}
 
	rep(i, 0, n) {
		input(p[i]);
	}
 
	int k;
	input(k);
	rep(i, 0, k) {
		input(l[i], r[i], a[i]);
		l[i]--;
		r[i]--;
	}

	rep(i, 0, n) {
		s[i] = 0;
		e[i] = k - 1;
		res[i] = -1;
	}
 
	int h = 19;
	SegTree<ll> t(m + 1);
	rep(i, 0, h) {
		vector<vector<int>> v(k);
		int c = 0;
		rep(j, 0, n) {
			if (s[j] <= e[j]) {
				v[(s[j] + e[j]) >> 1].push_back(j);
			}
		}
 
		fill(seg, seg + 4 * (m + 1), 0);
		ll z = 0;
		rep(j, 0, k) {
			t.upd(l[j], a[j]);
			t.upd(r[j] + 1, -a[j]);
			if (l[j] > r[j]) {
				z += a[j];
			}
 
			for (int o : v[j]) {
				ll y = 0;
				bool flag = false;
				for (int u : x[o]) {
					y += z + t.query(0, u);
					if (y >= p[o]) {
						flag = true;
						break;
					}
				}
 
				if (flag) {
					e[o] = j - 1;
					res[o] = j;
				}
				else {
					s[o] = j + 1;
				}
			}
		}
		// print(i);
		// cout.flush();
	}
 
	rep(i, 0, n) {
		if (res[i] == -1) {
			print("NIE");
		}
		else {
			print(res[i] + 1);
		}
	}
}
