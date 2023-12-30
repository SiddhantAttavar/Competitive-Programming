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
	setup();
	while (true) {
		int l;
		input(l);

		if (l == 0) {
			break;
		}

		int n;
		input(n);

		vector<int> c(n);
		arrPut(c);
		c.insert(c.begin(), 0);
		c.push_back(l);
		n += 2;

		vector<vector<int>> dp(n, vector<int>(n, 1e9));
		range(i, 0, n) {
			dp[i][i] = 0;
		}
		range(i, 0, n - 1) {
			dp[i][i + 1] = 0;
		}
		range(x, 3, n + 1) {
			range(i, 0, n - x + 1) {
				int j = i + x - 1;
				range(k, i + 1, j) {
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + c[j] - c[i]);
				}
			}
		}
		// range(i, 0, n) {
		// 	arrPrint(dp[i]);
		// }

		printf("The minimum cutting is %Ld.\n", dp[0][n - 1]);
	}
}
