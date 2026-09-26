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

void build(int c, int l, int r, vector<vector<pii>> &s, vi &x) {
	if (l == r) {
		s[c] = {{x[l], x[l]}};
		return;
	}

	int m = (l + r) / 2;
	build(2 * c, l, m, s, x);
	build(2 * c + 1, m + 1, r, s, x);

	s[c].resize(r - l + 1);
	merge(all(s[2 * c]), all(s[2 * c + 1]), s[c].begin());

	int a = 0;
	rep(i, 0, sz(s[c])) {
		a += s[c][i].first;
		s[c][i].second = a;
	}
}

array<int, 6> query(int c, int l, int r, int s, int e, int u, int v, vector<vector<pii>> &t) {
	if (s > e or l > e or r < s) {
		return {0, 0};
	}

	if (s <= l and r <= e) {
		int i = lower_bound(all(t[c]), make_pair(v, (int) 1e18)) - t[c].begin() - 1;
		if (i == -1) {
			return {0, 0, 0, 0, t[c].back().second, sz(t[c])};
		}
		int j = lower_bound(all(t[c]), make_pair(u, (int) -1)) - t[c].begin() - 1;
		if (j == -1) {
			return {0, 0, t[c][i].second, i + 1, t[c].back().second - t[c][i].second, sz(t[c]) - i - 1};
		}
		return {t[c][j].second, j + 1, t[c][i].second - t[c][j].second, i - j, t[c].back().second - t[c][i].second, sz(t[c]) - i - 1};
	}

	int m = (l + r) / 2;
	auto [x1, y1, x2, y2, x3, y3] = query(2 * c, l, m, s, e, u, v, t);
	auto [p1, q1, p2, q2, p3, q3] = query(2 * c + 1, m + 1, r, s, e, u, v, t);
	return {x1 + p1, y1 + q1, x2 + p2, y2 + q2, x3 + p3, y3 + q3};
}

int32_t main() {
	setup();

	int n, m, q;
	input(n, m, q);


	vi l(n), r(n);
	rep(i, 0, n) {
		input(l[i], r[i]);
		l[i]--;
		r[i]--;
	}

	vector<vector<pii>> s(4 * n), t(4 * n);
	build(1, 0, n - 1, s, l);
	build(1, 0, n - 1, t, r);

	while (q--) {
		int a, b, c, d;
		input(a, b, c, d);

		a--;
		b--;
		c--;
		d--;

		int res = 0;

		auto [u1, v1, u2, v2, u3, v3] = query(1, 0, n - 1, a, b, c, d, s);
		auto [f1, g1, f2, g2, f3, g3] = query(1, 0, n - 1, a, b, c, d, t);

		res -= v1 * c;
		res += g1 * c;
		res -= g1;

		res -= u2;
		res += f2;

		res -= v3 * d;
		res += g3 * d;
		res -= v3;

		res += b - a + 1;
		print(res);
	}
}
