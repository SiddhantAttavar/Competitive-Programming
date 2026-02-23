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
const int inv2 = (MOD + 1) / 2;

vector<vi> get(vi &a, vi &b, vector<vi> &p, int x) {
	int n = sz(a);
	vector<vi> dp(n, vi(n, 0));
	dp[x][x] = 1;
	rep(l, 1, n + 1) {
		rep(i, 0, n - l + 1) {
			int j = i + l - 1;
			if (i > x or j < x) {
				continue;
			}
			int s = p[i][j] + a[x] - b[x];
			bool b = i and s >= a[i - 1], c = j < n - 1 and s >= a[j + 1];
			if (b and c) {
				dp[i - 1][j] = (dp[i - 1][j] + dp[i][j] * inv2) % MOD;
				dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * inv2) % MOD;
			}
			else if (b) {
				dp[i - 1][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
			}
			else if (c) {
				dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * inv2) % MOD;
			}
		}
	}
	return dp;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int x, y;
		input(x, y);
		x--;
		y--;

		vi a(n), b(n);
		arrput(a);
		arrput(b);

		vector<vi> p(n, vi(n, 0));
		rep(i, 0, n) {
			p[i][i] = b[i];
			rep(j, i + 1, n) {
				p[i][j] = p[i][j - 1] + b[j];
			}
		}

		vector<vi> dpx = get(a, b, p, x), dpy = get(a, b, p, y);
		int res = 0;
		for (int k = 1; k <= n; k += 2) {
			rep(i, 0, n) {
				int l = i - (k + 1) / 2, r = i + 1 + k / 2;
				if (l < 0 or l > x or i < x) {
					continue;
				}
				if (r >= n or r < y or i + 1 > y) {
					continue;
				}
				int s = p[l][i] + a[x] - b[x], t = p[i + 1][r] + a[y] - b[y];
				if (s < t) {
					continue;
				}
				bool b = l and s >= a[l - 1];
				if (b) {
					res = (res + dpx[l][i] * dpy[i + 1][r] % MOD * inv2) % MOD;
				}
				else {
					res = (res + dpx[l][i] * dpy[i + 1][r]) % MOD;
				}
			}
			rep(i, 0, n) {
				int l = i - k / 2, r = i + 1 + (k + 1) / 2;
				if (l < 0 or l > y or i < y) {
					continue;
				}
				if (r >= n or r < x or i + 1 > x) {
					continue;
				}
				int s = p[l][i] + a[y] - b[y], t = p[i + 1][r] + a[x] - b[x];
				if (s > t) {
					continue;
				}
				bool b = r < n - 1 and t >= a[r + 1];
				if (b) {
					res = (res + dpx[l][i] * dpy[i + 1][r] % MOD * inv2) % MOD;
				}
				else {
					res = (res + dpx[l][i] * dpy[i + 1][r]) % MOD;
				}
			}
		}

		print(res);
	}
}
