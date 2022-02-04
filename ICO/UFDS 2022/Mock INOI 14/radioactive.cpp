// https://codebreaker.xyz/problem/radioactive
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
	
	int MOD = 1e9 + 7;
	int n, c;
	input(n, c);
	c = min(c, n);

	vector<int> dp1(n), dp2(n);
	dp1[0] = 1;
	dp2[0] = 1;
	int curr = dp1[0];
	range(i, 1, n) {
		dp1[i] = dp2[i - 1];
		dp2[i] = (dp2[i - 1] + curr) % MOD;
		curr = (curr + dp1[i]) % MOD;
		if (i - c >= 0) {
			curr = (curr - dp1[i - c] + MOD) % MOD;
		}
	}

	int res = dp2[n - 1];
	range(j, 0, c) {
		res = (res + dp1[n - j - 1]) % MOD;
	}
	print(res);
}
