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
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	int N = 5000;
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	range(i, 0, N + 1) {
		dp[i][0] = 1;
	}
	range(i, 0, N + 1) {
		dp[i][i] = 1;
	}
	range(i, 2, N + 1) {
		range(j, 1, i) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int res = 0;
		range(i, 1, n + 1) {
			for (int j = 0; 2 * j + 1 <= i; j++) {
				res = (res + i * ((dp[i - 1][j] * dp[n - i][i - (2 * j + 1)]) % MOD)) % MOD;
			}
		}
		for (int i = n + 1 + n % 2; i <= 2 * n + 1; i += 2) {
			res = (res + i * dp[n][(i - 1) / 2]) % MOD;
		}
		print(res);
	}
}
