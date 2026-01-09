#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define ll long long

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; T (*cmb)(T a, T b);
	int n; vector<T> seg;
	SegTree(int _n, T id, T _cmb(T, T)) {
		ID = id; cmb = _cmb;
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); 
	}
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	int query(int x) { // set val at position p
		int p = x;
		int res = seg[p += n].query(x);
		for (p /= 2; p; p /= 2) res = max(res, seg[p].query(x));
		return res;
	}
	void add(int l, int r, int a, int b) {	// zero-indexed, inclusive
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) seg[l++].add(a, b);
			if (r&1) seg[--r].add(a, b);
		}
	}
};

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		if (empty()) return -1e18;
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int N = 1e5;

int32_t main() {
	setup();

	int n;
	input(n);

	SegTree<LineContainer> s(N + 1, {}, [](LineContainer a, LineContainer b) {
		LineContainer c = a;
		for (Line l : b) {
			c.add(l.k, l.m);
		}
		return c;
	});
	rep(i, 0, n) {
		int o;
		input(o);

		if (o == 1) {
			int a, b, l, r;
			input(a, b, l, r);
			s.add(l, r, a, b);
		}
		else {
			int x;
			input(x);
			int res = s.query(x);
			if (res == -1e18) {
				print("NO");
			}
			else {
				print(res);
			}
		}
	}
}
