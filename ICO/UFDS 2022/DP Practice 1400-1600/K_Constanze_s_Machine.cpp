#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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

	for (char c : s) {
		if (c == 'w' or c == 'm') {
			print(0);
			return 0;
		}
	}

	int n = s.size();
	vector<int> dp(n, 1);
	if (s[0] == s[1] and (s[0] == 'u' or s[0] == 'n')) {
		dp[1] = 2;
	}
	range(i, 2, n) {
		dp[i] = dp[i - 1];
		if (s[i - 1] == s[i] and (s[i] == 'u' or s[i] == 'n')) {
			dp[i] += dp[i - 2];
			dp[i] %= (int) (1e9 + 7);
		}
	}

	print(dp[n - 1]);
}
