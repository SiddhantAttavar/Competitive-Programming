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
const int MOD = 998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), f(n, 0);
		arrput(a);

		rep(i, 0, n) {
			a[i]--;
			f[a[i]]++;
		}
		sort(f.begin(), f.end());

		int res = 1;
		for (int i : f) {
			res = res * i % MOD;
		}

		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		rep(i, 0, n) {
			int x = 0, y = 1;
			rep(j, i + 1, n) {
				x += f[j];
				y = y * f[j] % MOD;
			}

			rep(j, max(0ll, f[i] - x), n + 1) {
				res = (res + dp[j] * y) % MOD;
			}

			for (int j = n; j >= f[i]; j--) {
				dp[j] = (dp[j] + dp[j - f[i]] * f[i]) % MOD;
			}
		}
		print(res);
	}
}
