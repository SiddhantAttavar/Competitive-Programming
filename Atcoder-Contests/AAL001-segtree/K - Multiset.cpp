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
		p += n; seg[p] = cmb(val, seg[p]); for (p /= 2; p; p /= 2) pull(p); }
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

	int n, q;
	input(n, q);

	vi a(n);
	arrput(a);

	vector<pii> e(q);
	vi v = a;
	rep(i, 0, q) {
		int o;
		input(o);
		if (o == 3) {
			e[i] = {3, -1};
		}
		else {
			int x;
			input(x);
			e[i] = {o, x};
			v.push_back(x);
		}
	}

	sort(all(v));
	v.erase(unique(all(v)), v.end());

	SegTree<pii> s(sz(v), {0, 0}, [](pii a, pii b) -> pii {
		return {(a.first + b.first) % MOD, (a.second + b.second) % MOD};
	});

	int res = 0;
	sort(all(a));
	rep(i, 0, n) {
		res = (res + (i + 1) * a[i]) % MOD;
		int j = lower_bound(all(v), a[i]) - v.begin();
		s.upd(j, {a[i], 1});
	}

	for (auto [o, x] : e) {
		if (o == 1) {
			int j = lower_bound(all(v), x) - v.begin();
			int r = j ? s.query(0, j - 1).second : 0;
			res = (res + (r + 1) * x) % MOD;
			res = (res + s.query(j, sz(v) - 1).first) % MOD;
			s.upd(j, {x, 1});
		}
		else if (o == 2) {
			int j = lower_bound(all(v), x) - v.begin();
			int r = j ? s.query(0, j - 1).second : 0;
			s.upd(j, {(MOD - x) % MOD, MOD - 1});
			res = (res - (r + 1) * x % MOD + MOD) % MOD;
			res = (res - s.query(j, sz(v) - 1).first + MOD) % MOD;
		}
		else {
			print(res);
		}
	}
}
