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

	int n, x;
	input(n, x);

	vector<int> c(n);
	arrPut(c);

	vector<int> dp(x + 1, 1e18);
	dp[0] = 0;
	range(i, 1, x + 1) {
		range(j, 0, n) {
			if (i >= c[j]) {
				dp[i] = min(dp[i], dp[i - c[j]] + 1);
			}
		}
	}

	if (dp[x] == (int) 1e18) {
		print(-1);
	}
	else {
		print(dp[x]);
	}
}
