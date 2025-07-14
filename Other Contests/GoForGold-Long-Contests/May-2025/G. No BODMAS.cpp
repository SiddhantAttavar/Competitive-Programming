#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
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

vector<int> build(int i, vector<int> &a, vector<char> &v) {
	vector<int> l(10);
	if (v[i] == '+') {
		rep(j, 0, 10) {
			l[j] = (j + a[i + 1]) % 10;
		}
	}
	else if (v[i] == '-') {
		rep(j, 0, 10) {
			l[j] = ((j - a[i + 1]) % 10 + 10) % 10;
		}
	}
	else if (v[i] == '*') {
		rep(j, 0, 10) {
			l[j] = (j * a[i + 1]) % 10;
		}
	}
	else {
		rep(j, 0, 10) {
			l[j] = 1;
			rep(k, 0, a[i + 1] % 9) {
				l[j] *= j;
			}
			l[j] %= 10;
		}
	}
	return l;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrput(a);

		vector<char> v(n - 1);
		arrput(v);

		vector<int> l(10);
		rep(i, 0, 10) {
			l[i] = i;
		}

		SegTree<vector<int>> s(n - 1, l, [](vector<int> a, vector<int> b) {
			vector<int> l(10);
			rep(i, 0, 10) {
				l[i] = b[a[i]];
			}
			return l;
		});

		rep(i, 0, n - 1) {
			s.upd(i, build(i, a, v));
		}

		while (q--) {
			int o;
			input(o);

			if (o == 1) {
				int i, x;
				input(i, x);

				a[i - 1] = x;
				if (i >= 2) {
					s.upd(i - 2, build(i - 2, a, v));
				}
			}
			else if (o == 2) {
				int i;
				char x;
				input(i, x);

				v[i - 1] = x;
				s.upd(i - 1, build(i - 1, a, v));
			}
			else {
				int l, r;
				input(l, r);

				l--;
				r--;
				print(s.query(l, r - 1)[a[l] % 10]);
			}
		}
	}
}
