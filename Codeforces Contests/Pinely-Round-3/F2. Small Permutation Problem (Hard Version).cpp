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
const int MOD = 998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		int res = 1, p = 0;
		vi dp(n + 1, 0);
		dp[0] = 1;
		rep(i, 0, n) {
			vi ndp(n + 1, 0);
			for (int j = n; j >= 0; j--) {
				if (a[i] != -1 and a[i] != j) {
					continue;
				}
				ndp[j] = dp[j];
				if (j) {
					ndp[j] = (ndp[j] + dp[j - 1] * (2 * i - 2 * j + 3)) % MOD;
				}
				if (j > 1) {
					ndp[j] = (ndp[j] + dp[j - 2] * (i - j + 2) % MOD * (i - j + 2)) % MOD;
				}
			}
			dp = ndp;
		}
		print(dp[n]);
	}
}
