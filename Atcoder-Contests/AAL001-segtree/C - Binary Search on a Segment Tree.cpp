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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

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
	int first(int l, int &t, int c = -1, int s = -1, int e = -1) {
		if (c == -1) {
			return first(l, t, 1, 0, n - 1);
		}
		if (e < l) {
			return -1;
		}
		if (s >= l and seg[c] < t) {
			t -= seg[c];
			return -1;
		}
		if (s == e) {
			return s;
		}
		int m = (s + e) / 2;
		int res = first(l, t, 2 * c, s, m);
		if (res != -1) {
			return res;
		}
		return first(l, t, 2 * c + 1, m + 1, e);
	}
	int last(int r, int &t, int c = -1, int s = -1, int e = -1) {
		if (c == -1) {
			return last(r, t, 1, 0, n - 1);
		}
		if (s > r) {
			return -1;
		}
		if (e <= r and seg[c] < t) {
			t -= seg[c];
			return -1;
		}
		if (s == e) {
			return s;
		}
		int m = (s + e) / 2;
		int res = last(r, t, 2 * c + 1, m + 1, e);
		if (res != -1) {
			return res;
		}
		return last(r, t, 2 * c, s, m);
	}
};

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	SegTree<int> s(n, 0, [](int a, int b) {
		return a + b;
	});

	vi a(n);
	arrput(a);

	rep(i, 0, n) {
		s.upd(i, a[i]);
	}

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int i, x;
			input(i, x);
			s.upd(i - 1, x);
		}
		else if (o == 2) {
			int l, t;
			input(l, t);
			int res = s.first(l - 1, t);
			print(res == -1 ? n + 1 : res + 1);
		}
		else {
			int r, t;
			input(r, t);
			int res = s.last(r - 1, t);
			print(res + 1);
		}
	}
}
