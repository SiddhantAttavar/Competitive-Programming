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

const int N = 300;
vector<SegTree<int>> s(N + 1, SegTree<int>(N + 1, 0, [](int a, int b) {
	return (a + b) % MOD;
}));
vector<SegTree<int>> t(N + 1, SegTree<int>(N + 1, 0, [](int a, int b) {
	return (a + b) % MOD;
}));

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrput(a);

		vector<vector<int>> dp(N + 1, vector<int>(N + 1));
		dp[0][0] = 1;
		rep(i, 0, N + 1) {
			rep(j, 0, N + 1) {
				s[i].upd(j, dp[i][j]);
				t[j].upd(i, dp[i][j]);
			}
		}
		for (int i : a) {
			rep(j, 0, i + 1) {
				dp[j][i] = (dp[j][i] + s[j].query(j, i)) % MOD;
			}
			rep(k, i + 1, N + 1) {
				dp[i][k] = (dp[i][k] + t[k].query(0, i)) % MOD;
			}
			rep(j, 0, N + 1) {
				s[i].upd(j, dp[i][j]);
				t[j].upd(i, dp[i][j]);

				s[j].upd(i, dp[j][i]);
				t[i].upd(j, dp[j][i]);
			}
		}

		int res = 0;
		rep(i, 0, N + 1) {
			res = (res + s[i].query(0, N)) % MOD;
		}
		print(res);
	}
}
