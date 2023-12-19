#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> a(n, vector<int>(3));
		range(i, 0, 3) {
			range(j, 0, n) {
				input(a[j][i]);
			}
		}
		vector<int> l = {0, 1, 2};

		int res = 0;
		do {
			vector<vector<int>> dp(n, vector<int>(3, 0));
			dp[0][l[0]] = a[0][l[0]];
			range(i, 1, n) {
				dp[i][l[0]] = max(dp[i - 1][l[0]], a[i][l[0]]);
			}
			range(i, 1, n) {
				dp[i][l[1]] = max(dp[i - 1][l[1]], a[i][l[1]] + dp[i - 1][l[0]]);
			}
			range(i, 2, n) {
				dp[i][l[2]] = max(dp[i - 1][l[2]], a[i][l[2]] + dp[i - 1][l[1]]);
			}
			res = max(res, dp[n - 1][l[2]]);
		} while (next_permutation(l.begin(), l.end()));

		print(res);
	}
}
