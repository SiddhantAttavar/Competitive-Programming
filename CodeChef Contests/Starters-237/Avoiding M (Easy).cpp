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
const int MOD = 998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vi dp(n + 1, 0);
		dp[0] = 1;
		rep(i, 1, n + 1) {
			dp[i] = dp[i - 1] * (n - m) % MOD;
		}
		rep(j, 1, m) {
			vi ndp(n + 1, 0);
			ndp[0] = 1;
			rep(i, 1, n + 1) {
				ndp[i] = (ndp[i - 1] * (n - j) + dp[i - 1] * j) % MOD;
			}
			dp = ndp;
		}

		vi f = dp;
		rep(x, 0, n + 1) {
			rep(y, 0, x) {
				f[x] = (f[x] + dp[y] * f[x - y - 1]) % MOD;
			}
		}
		print(f[n]);
	}
}
