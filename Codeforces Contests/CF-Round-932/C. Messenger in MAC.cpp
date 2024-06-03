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
const int MOD = (int) 1e15 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, l;
		input(n, l);

		vector<pair<int, int>> a(n);
		range(i, 0, n) {
			input(a[i].second, a[i].first);
		}
		sort(a.begin(), a.end());

		vector<vector<int>> dp(n, vector<int>(n, 1e15));
		int res = 0;
		range(i, 0, n) {
			dp[i][0] = a[i].second;
			if (dp[i][0] <= l) {
				res = 1;
			}
		}
		range(j, 1, n) {
			int m = 1e15;
			range(i, 0, n) {
				dp[i][j] = a[i].second + a[i].first + m;
				m = min(m, dp[i][j - 1] - a[i].first);
				if (dp[i][j] <= l) {
					res = j + 1;
				}
			}
		}

		print(res);
	}
}
