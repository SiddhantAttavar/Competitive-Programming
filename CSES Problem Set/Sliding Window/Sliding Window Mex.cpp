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
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
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
		seg[p += n] += val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
	int get(int c = -1, int l = -1, int r = -1) {
		if (c == -1) {
			return get(1, 0, n - 1);
		}
		if (l == r) {
			return l;
		}
		int m = (l + r) / 2;
		if (!seg[2 * c]) {
			return get(2 * c, l, m);
		}
		return get(2 * c + 1, m + 1, r);
	}
};

int32_t main() {
	setup();

	int n, k;
	input(n, k);

	vi x(n);
	arrput(x);

	SegTree<int> s(k + 1, 1e18, [](int a, int b) {
		return min(a, b);
	});
	rep(i, 0, k + 1) {
		s.seg[s.n + i] = 0;
	}
	for (int i = s.n - 1; i >= 0; i--) {
		s.pull(i);
	}

	rep(i, 0, k) {
		if (x[i] < k) {
			s.upd(x[i], 1);
		}
	}

	cout << s.get();
	rep(i, k, n) {
		if (x[i] < k) {
			s.upd(x[i], 1);
		}
		if (x[i - k] < k) {
			s.upd(x[i - k], -1);
		}
		cout << ' ' << s.get();
	}
	cout << endl;
}
