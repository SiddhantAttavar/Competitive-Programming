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
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		vector<vector<int>> dp(n + 1, vector<int>(k + 1));
		range(i, 0, n) {
			range(j, 0, k + 1) {
				dp[i + 1][j] = dp[i][j] + a[i];
				if (j > i) {
					if (j) {
						dp[i + 1][j] = dp[i + 1][j - 1];
					}
					continue;
				}

				int m = a[i];
				int s = a[i];
				range(x, 1, j + 1) {
					m = min(m, a[i - x]);
					s += a[i - x];
					dp[i + 1][j] = min(dp[i + 1][j], (x + 1) * m + dp[i - x][j - x]);
				}
			}
		}
		// range(i, 0, n + 1) {
		// 	arrPrint(dp[i]);
		// }

		print(*min_element(dp[n].begin(), dp[n].end()));
	}
}
