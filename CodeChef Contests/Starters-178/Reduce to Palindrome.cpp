#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	int N = 10;
	vector<vector<int>> dp(N + 1, vector<int>(1 << 11, false));
	dp[0][0] = true;
	dp[1][0] = true;
	dp[1][1] = true;
	dp[2][1] = true;
	dp[2][3] = true;
	rep(l, 2, 11) {
		rep(x, 0, 1 << l) {
			rep(i, 0, l - 1) {
				int y = x & ~(3 << i);
				dp[l][x] |= dp[l - 2][y];
			}
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		int res = 0;
		rep(i, 0, n) {
			res += (i + 1) * (i + 1);
			res -= i * (i + 1) / 2;
		}

		for (int l = 2; l <= N; l += 2) {
			rep(i, 0, n - l + 1) {
				int j = i + l - 1;
				int x = 0;
				rep(k, i, j + 1) {
					x = (x << 1) | (s[k] == '1');
				}
				res -= !dp[l][x];
			}
		}
		print(res);
	}
}
