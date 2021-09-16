#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
#define int ll

signed main() {
	setup();
	int n; input(n);
	int a[n], b[n];
	arrPut(a);
	arrPut(b);

	ll totalSum = 0;
	range(i, 0, n) {
		totalSum += a[i] * b[i];
	}

	ll dp[n][n];
	range(i, 0, n - 1) {
		dp[i][i] = totalSum;
		dp[i][i + 1] = totalSum - a[i] * b[i] - a[i + 1] * b[i + 1] + a[i] * b[i + 1] + a[i + 1] * b[i];
	}
	dp[n - 1][n - 1] = totalSum;

	range(l, 3, n + 1) {
		range(i, 0, n - l + 1) {
			int j = i + l - 1;
			dp[i][j] = dp[i + 1][j - 1] - a[i] * b[i] - a[j] * b[j] + a[i] * b[j] + a[j] * b[i];
		}
	}

	ll res = 0;
	range(i, 0, n) {
		range(j, i, n) {
			res = max(res, dp[i][j]);
		}
	}
	print(res);
}