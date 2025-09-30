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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> v(n), a(n), b(n);
		arrput(v);
		arrput(a);
		arrput(b);

		SegTree<array<int, 3>> s(n + 1, {(int) -1e18, 0, 0}, [](array<int, 3> a, array<int, 3> b) {
			return array<int, 3>{
				max(a[0] - b[2], b[0]),
				max(b[1], a[1] + b[2]),
				a[2] + b[2]
			};
		});

		vector<int> c(n), d(n);
		rep(i, 0, n) {
			a[i]--;
			b[i]--;
			c[a[i]] = i;
			d[b[i]] = i;
		}

		vector<int> p(n + 1, 0);
		rep(i, 0, n) {
			p[i + 1] = p[i] + v[a[i]];
		}

		vector<int> dp(n + 1);
		s.upd(0, {0, 0, 0});
		for (int j : b) {
			int i = c[j];
			dp[i + 1] = s.query(0, i)[0] + p[i + 1];
			// print(i, s.query(0, i)[2]);
			s.upd(i + 1, {dp[i + 1] - p[i + 1], max(0ll, v[a[i]]), v[a[i]]});
			// arrprint(dp);
		}

		print(*max_element(dp.begin(), dp.end()));
	}
}
