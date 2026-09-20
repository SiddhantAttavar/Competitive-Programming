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

/**
 * Author: Lucian Bicsi
 * Description: 1D point update and range query where \texttt{cmb} is
 	* any associative operation. \texttt{seg[1]==query(0,N-1)}.
 * Time: O(\log N)
 * Source: 
	* http://codeforces.com/blog/entry/18051
	* KACTL
 */

const int K = 10, INF = 1e18, N = 1 << 20;
using T = array<array<int, K>, K>;
T seg[N];

template<typename T> struct SegTree { // cmb(ID,b) = b
	T ID; function<T(T, T)> cmb; function<T(int)> f;
	int n;
	SegTree(int _n, T id, function<T(T, T)> _cmb, function<T(int)> _f) {
		ID = id; cmb = _cmb; f = _f;
		for (n = 1; n < _n; ) n *= 2; 
		fill(seg, seg + n, ID);
	}
	T get(int p) {return p < n ? seg[p] : f(p - n);}
	void pull(int p) { seg[p] = cmb(get(2*p),get(2*p+1)); }
	void upd(int p) { // set val at position p
		p += n; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra, get(l++));
			if (r&1) rb = cmb(get(--r), rb);
		}
		return cmb(ra, rb);
	}
	/// int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
	/// 	if (r < lo || val > seg[ind]) return -1;
	/// 	if (l == r) return l;
	/// 	int m = (l+r)/2;
	/// 	int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
	/// 	return first_at_least(lo,val,2*ind+1,m+1,r);
	/// }
};


T get(int d, int s, int x) {
	T res;
	rep(i, 0, K) {
		rep(j, 0, K) {
			res[i][j] = i == j and i < d ? 0 : INF;
		}
	}
	rep(i, 0, min(d, x)) {
		rep(j, 0, x) {
			res[i][j] = s * ((d + j - i + x - 1) / x - 1);
		}
	}
	return res;
}

array<int, K> mult(array<int, K> &a, T &b) {
	array<int, K> res;
	rep(i, 0, K) {
		res[i] = INF;
		rep(j, 0, K) {
			res[i] = min(res[i], a[j] + b[j][i]);
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n, q, x;
	input(n, q, x);

	vi a(n), b(n);
	arrput(a);
	arrput(b);

	T z;
	rep(i, 0, K) {
		rep(j, 0, K) {
			z[i][j] = i == j ? 0 : INF;
		}
	}
	SegTree<T> s(n - 1, z, [](T a, T b) {
		T res;
		rep(i, 0, K) {
			rep(j, 0, K) {
				res[i][j] = INF;
				rep(k, 0, K) {
					res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
				}
			}
		}
		return res;
	}, [&](int i) {
		if (i >= n - 1) {
			return z;
		}
		return get(a[i], b[i], x);
	});

	for (int i = s.n - 1; i > 0; i--) {
		s.pull(i);
	}

	while (q--) {
		char o;
		input(o);

		if (o == '1') {
			int i, z;
			input(i, z);

			i--;
			a[i] = z;
			if (i < n - 1) {
				s.upd(i);
			}
		}
		else if (o == '2') {
			int i, z;
			input(i, z);

			i--;
			b[i] = z;
			if (i < n - 1) {
				s.upd(i);
			}
		}
		else {
			int l, r;
			input(l, r);

			l--;
			r--;
			array<int, K> z;
			fill(all(z), INF);
			z[0] = 0;
			if (l < r) {
				z = s.query(l, r - 1)[0];
			}

			int res = INF;
			rep(i, 0, min(K, a[r])) {
				res = min(res, z[i] + b[r] * ((a[r] - 1 - i + x - 1) / x));
			}
			print(res);
		}
	}
}
