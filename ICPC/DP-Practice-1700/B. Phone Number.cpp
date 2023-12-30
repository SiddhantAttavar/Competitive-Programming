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

	string s;
	input(s);

	int n = s.size();

	vector<vector<int>> dp(n, vector<int>(10, 1));
	for (int i = n - 2; i >= 0; i--) {
		range(j, 0, 10) {
			int x = ((s[i + 1] - '0') + j);
			if (x % 2 == 0) {
				dp[i][j] = dp[i + 1][x / 2];
			}
			else {
				dp[i][j] = dp[i + 1][x / 2] + dp[i + 1][x / 2 + 1];
			}
		}
	}

	// range(i, 0, n) {
	// 	arrPrint(dp[i]);
	// }

	int res = 0;
	range(j, 0, 10) {
		res += dp[0][j];
	}

	bool flag = true;
	range(i, 1, n) {
		if (abs(s[i] - s[i - 1]) > 1) {
			flag = false;
			break;
		}
	}

	print(res - flag);
}
