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
const int MOD = 998244353;
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
};

int inv(int i, int n, SegTree<array<int, 3>> &s, int x) {
	array<int, 3> a = i ? s.query(0, i - 1) : array<int, 3>{0, 0, 0};
	array<int, 3> b = i < n - 1 ? s.query(i + 1, n - 1) : array<int, 3>{0, 0, 0};
	if (x == 0) {
		return a[1] + a[2];
	}
	else if (x == 1) {
		return a[2] + b[0];
	}
	else {
		return b[0] + b[1];
	}
}

array<int, 6> get(int i, vi &a, string &t) {
	if (t[i] == 'R') {
		return {a[i] % MOD, 0, 0, 0, 0, 0};
	}
	else if (t[i] == 'G') {
		return {0, a[i] % MOD, 0, 0, 0, 0};
	}
	else {
		return {0, 0, a[i] % MOD, 0, 0, 0};
	}
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	SegTree<array<int, 6>> s(n, {0, 0, 0, 0, 0, 0}, [](array<int, 6> a, array<int, 6> b) -> array<int, 6> {
		return {
			(a[0] + b[0]) % MOD,
			(a[1] + b[1]) % MOD,
			(a[2] + b[2]) % MOD,
			(a[3] + b[3] + a[0] * b[1]) % MOD,
			(a[4] + b[4] + a[1] * b[2]) % MOD,
			(a[5] + b[5] + a[3] * b[2] + a[0] * b[4]) % MOD,
		};
	});

	vi a(n);
	arrput(a);

	string t;
	input(t);

	rep(i, 0, n) {
		s.upd(i, get(i, a, t));
	}

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int i, x;
			input(i, x);

			i--;
			a[i] = x;
			s.upd(i, get(i, a, t));
		}
		else {
			int l, r;
			input(l, r);
			print(s.query(l - 1, r - 1)[5]);
		}
	}
}
