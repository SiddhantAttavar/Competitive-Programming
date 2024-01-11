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

	int MOD = (int) 1e9 + 7;

	int t, k;
	input(t, k);

	int N = 1e5;
	vector<int> pref(N + 2, 0);
	vector<int> dp(N + 1, 0);
	dp[0] = 1;
	pref[1] = 1;
	range(i, 1, N + 1) {
		dp[i] = dp[i - 1];
		if (i >= k) {
			dp[i] = (dp[i] + dp[i - k]) % MOD;
		}
		pref[i + 1] = (pref[i] + dp[i]) % MOD;
	}

	while (t--) {
		int a, b;
		input(a, b);

		print((pref[b + 1] - pref[a] + MOD) % MOD);
	}
}
