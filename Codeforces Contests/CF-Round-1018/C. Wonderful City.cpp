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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> h(n, vector<int>(n));
		rep(i, 0, n) {
			arrput(h[i]);
		}

		vector<int> a(n), b(n);
		arrput(a);
		arrput(b);

		vector<int> f(n, 1e15), g(n, 1e15);
		f[0] = 0;
		g[0] = a[0];
		rep(i, 1, n) {
			bool w = true, x = true, y = true, z = true;
			rep(j, 0, n) {
				w &= h[i - 1][j] != h[i][j];
				x &= h[i - 1][j] != h[i][j] + 1;
				y &= h[i - 1][j] + 1 != h[i][j];
				z &= h[i - 1][j] + 1 != h[i][j] + 1;
			}
			if (w) {
				f[i] = f[i - 1];
			}
			if (y) {
				f[i] = min(f[i], g[i - 1]);
			}
			if (x) {
				g[i] = min(g[i], f[i - 1] + a[i]);
			}
			if (z) {
				g[i] = min(g[i], g[i - 1] + a[i]);
			}
		}

		if (min(f[n - 1], g[n - 1]) == 1e15) {
			print(-1);
			continue;
		}
		int res = min(f[n - 1], g[n - 1]);

		f = vector<int>(n, 1e15);
		g = vector<int>(n, 1e15);
		f[0] = 0;
		g[0] = b[0];
		rep(i, 1, n) {
			bool w = true, x = true, y = true, z = true;
			rep(j, 0, n) {
				w &= h[j][i - 1] != h[j][i];
				x &= h[j][i - 1] != h[j][i] + 1;
				y &= h[j][i - 1] + 1 != h[j][i];
				z &= h[j][i - 1] + 1 != h[j][i] + 1;
			}
			if (w) {
				f[i] = f[i - 1];
			}
			if (y) {
				f[i] = min(f[i], g[i - 1]);
			}
			if (x) {
				g[i] = min(g[i], f[i - 1] + b[i]);
			}
			if (z) {
				g[i] = min(g[i], g[i - 1] + b[i]);
			}
		}

		if (min(f[n - 1], g[n - 1]) == 1e15) {
			print(-1);
			continue;
		}
		res += min(f[n - 1], g[n - 1]);
		print(res);
	}
}
