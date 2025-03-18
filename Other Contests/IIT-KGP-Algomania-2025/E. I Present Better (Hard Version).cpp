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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
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

const int N = 1e6 + 10;
SegTree<int> y(2 * N + 10, 0, [](int x, int y) {
	return x + y;
});
vector<int> z(2 * N + 10, 0);

int32_t main() {
	setup();
	int n, a, b;
	input(n, a, b);

	vector<int> p(n);
	arrput(p);
	p.push_back(-1);

	vector<int> f(n + 1), g(n + 1);
	int u = 0, v = 0;
	rep(i, 0, n + 1) {
		f[i] = u;
		g[i] = v;
		u -= (p[i] > a) - (p[i] < a);
		v -= (p[i] > b) - (p[i] < b);
	}

	int res = 0;
	rep(i, 0, n + 1) {
		z[g[i] + N]++;
		y.upd(g[i] + N, z[g[i] + N]);
		res += y.query(0, f[i] - (a < b) + (a > b) - 1 + N);
	}

	fill(y.seg.begin(), y.seg.end(), 0);
	fill(z.begin(), z.end(), 0);
	rep(i, 0, n + 1) {
		z[f[i] + N]++;
		y.upd(f[i] + N, z[f[i] + N]);
		res += y.query(g[i] + (a < b) - (a > b) + 1 + N, 2 * N - 1);
	}

	print(res);
}
