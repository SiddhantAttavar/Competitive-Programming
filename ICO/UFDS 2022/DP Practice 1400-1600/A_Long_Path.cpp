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
	
	const int MOD = 1e9 + 7;
	int n;
	input(n);

	vector<int> p(n);
	arrPut(p);
	range(i, 0, n) {
		p[i]--;
	}

	vector<int> dp(n + 1);
	dp[0] = 0;
	range(i, 1, n + 1) {
		dp[i] = (dp[i - 1] + (dp[i - 1] - dp[p[i - 1]]) + 2 + MOD) % MOD;
	}
	print(dp[n]);
}
