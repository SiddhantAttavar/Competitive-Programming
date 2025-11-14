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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<vector<int>> v(n + 1);
		rep(i, 0, 1 << n) {
			v[__builtin_popcount(i)].push_back(i);
		}

		vector<vector<int>> dp(1 << n, vector<int>(n, 0));
		rep(i, 0, n) {
			dp[1 << i][i] = 1;
		}
		rep(l, 2, n + 1) {
			for (int i : v[l]) {
				rep(u, 0, n) {
					if (!(i >> u & 1)) {
						continue;
					}
					rep(v, 0, n) {
						if (i >> v & 1 and v != u and abs(u - v) <= k) {
							dp[i][u] += dp[i ^ (1 << u)][v];
						}
					}
				}
			}
		}
		print(accumulate(dp.back().begin(), dp.back().end(), 0ll));
	}
}
