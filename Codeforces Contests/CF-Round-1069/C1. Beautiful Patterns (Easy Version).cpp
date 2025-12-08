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

int mpow(int a, int b, int p = MOD) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
int mdiv(int a, int b, int p = MOD) {
	return a * mpow(b, p - 2, p) % p;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, p;
		input(n, m, p);

		vector<int> powm(n + 1);
		powm[0] = 1;
		rep(i, 1, n + 1) {
			powm[i] = powm[i - 1] * m % p;
		}
 
		int z = 0, res = 0;
		int k = mdiv(1, powm[n], p);
		rep(i, 0, n) {
			vector<int> dp(n + 1, 0);
			dp[0] = powm[n];
			for (int l = 1; l <= n; l += 2) {
				if (i - l / 2 < 0 or i + l / 2 >= n) {
					break;
				}
				dp[(l + 1) / 2] = powm[n - l / 2];
			}
			rep(l, 0, n) {
				dp[l] = (dp[l] - dp[l + 1] + p) * k % p;
			}
			dp[n] = dp[n] * k % p;
			int x = 0, y = 0;
			rep(l, 0, n + 1) {
				x = (x + l * l * dp[l]) % p;
				y = (y + l * dp[l]) % p;
			}
			res = (res + x + 2 * y * z) % p;
			z = (z + y) % p;
		}
 
		rep(i, 0, n) {
			vector<int> dp(n + 1, 0);
			dp[0] = powm[n];
			for (int l = 2; l <= n; l += 2) {
				if (i - l / 2 + 1 < 0 or i + l / 2 >= n) {
					break;
				}
				dp[(l + 1) / 2] = powm[n - l / 2];
			}
			rep(l, 0, n) {
				dp[l] = (dp[l] - dp[l + 1] + p) * k % p;
			}
			dp[n] = dp[n] * k % p;
			int x = 0, y = 0;
			rep(l, 0, n + 1) {
				x = (x + l * l * dp[l]) % p;
				y = (y + l * dp[l]) % p;
			}
			res = (res + x + 2 * y * z) % p;
			z = (z + y) % p;
		}
 
		print(res);
	}
}
