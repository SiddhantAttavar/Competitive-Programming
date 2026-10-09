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

#define ld long double

ld dist(int i, int j, vi &x, vi &y) {
	return sqrtl((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int32_t main() {
	setup();

	int n;
	input(n);

	vi x(n), y(n);
	rep(i, 0, n) {
		input(x[i], y[i]);
	}

	vector<vector<ld>> f(n, vector<ld>(n, 0)), g(n, vector<ld>(n, 0));
	rep(l, 2, n + 1) {
		rep(i, 0, n) {
			int j = (i + l - 1) % n;
			int u = (i + 1) % n, v = (j + n - 1) % n;
			f[i][j] = max(f[u][j] + dist(i, u, x, y), g[u][j] + dist(i, j, x, y));
			g[i][j] = max(g[i][v] + dist(v, j, x, y), f[i][v] + dist(i, j, x, y));
		}
	}

	ld res = 0;
	rep(i, 0, n) {
		int j = (i + n - 1) % n;
		res = max({res, f[i][j], g[i][j]});
	}
	cout << fixed << setprecision(16) << res << endl;
}
