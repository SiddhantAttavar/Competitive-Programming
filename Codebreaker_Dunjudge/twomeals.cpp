// https://codebreaker.xyz/problem/twomeals
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup();
	
	int n;
	input(n);
	vector<int> t(n);
	arrPut(t);

	vector<int> dp1(n);
	dp1[0] = t[0];
	range(i, 1, n) {
		dp1[i] = t[i] + max(dp1[i - 1], 0ll);
	}
	dp1[0] = max(dp1[0], 0ll);
	range(i, 1, n) {
		dp1[i] = max(dp1[i], dp1[i - 1]);
	}

	vector<int> dp2(n);
	dp2[n - 1] = t[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		dp2[i] = t[i] + max(dp2[i + 1], 0ll);
	}
	dp2[n - 1] = max(dp2[n - 1], 0ll);
	for (int i = n - 2; i >= 0; i--) {
		dp2[i] = max(dp2[i], dp2[i + 1]);
	}
	
	int res = 0;
	range(i, 0, n - 1) {
		res = max(res, dp1[i] + dp2[i + 1]);
	}
	print(res);
}
