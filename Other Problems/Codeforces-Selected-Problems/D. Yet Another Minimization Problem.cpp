#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		int res = 0;
		for (int i : a) {
			res += i * i;
		}

		for (int i : b) {
			res += i * i;
		}

		res *= n - 2;

		int x = 0;
		for (int i : a) {
			x += i;
		}
		for (int i : b) {
			x += i;
		}

		vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
		dp[0][0] = true;
		range(i, 0, n) {
			range(j, a[i], x + 1) {
				dp[i + 1][j] = dp[i][j - a[i]];
			}
			range(j, b[i], x + 1) {
				dp[i + 1][j] = dp[i + 1][j] or dp[i][j - b[i]];
			}
		}

		int m = -1;
		range(i, 0, dp[n].size()) {
			if (dp[n][i] and abs(2 * m - x) > abs(2 * i - x)) {
				m = i;
			}
		}

		print(res + m * m + (x - m) * (x - m));
	}
}
