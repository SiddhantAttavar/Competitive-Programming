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
};

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	SegTree<int> s(n, 0, [](int a, int b) {
		return max(a, b);
	});

	vi a(n);
	arrput(a);

	vi b(n);
	int p = 0;
	set<int> t = {0};
	rep(i, 1, n) {
		if (a[i] != a[p]) {
			b[p] = i - p;
			s.upd(p, b[p]);
			p = i;
			t.insert(i);
		}
	}
	b[p] = n - p;
	s.upd(p, b[p]);

	while (q--) {
		int o;
		input(o);

		if (o == 1) {
			int i, x;
			input(i, x);

			i--;
			a[i] = x;
			t.insert(i);
			if (i + 1 < n) {
				t.insert(i + 1);
			}

			set<int>::iterator j = i ? prev(t.lower_bound(i)) : t.begin();
			while (j != t.end() and *j <= i + 1) {
				while (next(j) != t.end() and a[*j] == a[*next(j)]) {
					if (next(j) != t.end()) {
						b[*next(j)] = 0;
						s.upd(*next(j), b[*next(j)]);
					}
					t.erase(next(j));
				}
				b[*j] = next(j) == t.end() ? n - *j : *next(j) - *j;
				s.upd(*j, b[*j]);
				j = next(j);
			}
		}
		else {
			int l, r;
			input(l, r);

			l--;
			r--;

			set<int>::iterator j = t.lower_bound(l);
			if (j == t.end() or *j > r) {
				print(r - l + 1);
				continue;
			}
			set<int>::iterator k = prev(t.upper_bound(r));
			if (*k > l) {
				print(max({*j - l, r - *k + 1, s.query(l, *k - 1)}));
			}
			else {
				print(max(*j - l, r - *k + 1));
			}
		}
	}
}
