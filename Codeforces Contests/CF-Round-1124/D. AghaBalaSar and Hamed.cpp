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
		if (l > r) {
			return ID;
		}
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
	int last(int c = 1, int l = -1, int r = -1) {
		if (l == -1) {
			l = 0, r = n - 1;
		}
		if (!seg[c]) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		int m = (l + r) / 2;
		if (seg[2 * c + 1]) {
			return last(2 * c + 1, m + 1, r);
		}
		return last(2 * c, l, m);
	}
	/// int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
	/// 	if (r < lo || val > seg[ind]) return -1;
	/// 	if (l == r) return l;
	/// 	int m = (l+r)/2;
	/// 	int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
	/// 	return first_at_least(lo,val,2*ind+1,m+1,r);
	/// }
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi p(n);
		arrput(p);
		rep(i, 0, n) {
			p[i]--;
		}

		stack<int> s;
		vi r(n, -1);
		for (int i = n - 1; i >= 0; i--) {
			while (!s.empty() and p[i] > p[s.top()]) {
				s.pop();
			}
			if (!s.empty()) {
				r[i] = s.top();
			}
			s.push(i);
		}

		SegTree<int> t(n, 0, [](int a, int b) {
			return a + b;
		});

		vi y(n, 0), x(n), b(n, false);
		rep(i, 0, n) {
			x[i] = t.last();
			if (r[i] != -1 and x[i] != -1) {
				y[i] = t.query(r[i] + 1, x[i] - 1);
			}
			if (r[i] != -1 and r[r[i]] != -1 and (x[i] == -1 or (!b[r[r[i]]] and r[r[i]] < x[i]))) {
				y[i]++;
			}
			if (r[i] != -1) {
				t.upd(r[i], 1);
				b[r[i]] = true;
			}
		}

		vector<pii> dp(n);
		for (int i = n - 1; i >= 0; i--) {
			if (r[i] == -1) {
				dp[i] = {0, 1};
			}
			else if (x[i] == -1 or x[i] <= i or x[i] <= r[i]) {
				dp[i] = {
					dp[r[i]].first + dp[r[i]].second + 2 * (r[i] - i - 1),
					dp[r[i]].second + r[i] - i
				};
			}
			else {
				dp[i] = {
					2 * (r[i] - i - 1) + 1 + 
					3 * (x[i] - r[i] - 1) - y[i] + 
					dp[x[i]].first + 2 * dp[x[i]].second,
					dp[x[i]].second + x[i] - i
				};
			}
		}

		int res = n * (n - 1) / 2;
		rep(i, 0, n) {
			res += dp[i].first;
		}
		print(res);
	}
}
