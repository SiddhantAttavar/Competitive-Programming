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
	const int N = 1e4;
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> dp(n, vector<int>(N + 1, 0));
		rep(i, 0, n) {
			int k;
			input(k);
			rep(j, 0, k) {
				int t;
				input(t);
				dp[i][t] = 1;
			}
		}
		rep(i, 1, n) {
			dp[i][0] = -1e18;
		}

		rep(j, 1, N + 1) {
			rep(i, 0, n) {
				dp[i][j] += max({dp[i][j - 1], dp[max(0, i - 1)][j - 1], dp[min(n - 1, (int) i + 1)][j - 1]});
			}
		}

		int k = 0;
		rep(i, 0, n) {
			k = max(k, dp[i][N]);
		}
		bool flag = false;
		rep(j, 0, N + 1) {
			rep(i, 0, n) {
				if (dp[i][j] == k) {
					flag = true;
					break;
				}
			}
			if (flag) {
				print(k, j);
				break;
			}
		}
	}
}
