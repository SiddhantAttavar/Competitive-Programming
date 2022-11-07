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

	int n = s.size();
	vector<int> a(n);
	range(i, 0, n) {
		a[i] = (s[i] - '0') % 3;
	}

	vector<vector<int>> dp(n, vector<int>(3, -1));
	dp[0][a[0]] = 0;
	dp[0][0] += !a[0];
	range(i, 1, n) {
		range(j, 0, 3) {
			if (dp[i - 1][(j - a[i] + 3) % 3] != -1) {
				dp[i][j] = dp[i - 1][(j - a[i] + 3) % 3];
			}
		}
		dp[i][a[i]] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][a[i]]});
		dp[i][0]++;
	}

	print(max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}));
}
