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
#define int long long

int32_t main() {
	const int MOD = 1e9 + 7;
	setup();
	int n; input(n);
	vector<int> a(n); arrPut(a);
	
	stack<int> lower, upper;
	vector<int> maxEnd(n);
	vector<int> dp(n);
	dp[n - 1] = 2;
	lower.push(n - 1);
	upper.push(n - 1);
	maxEnd[n - 1] = -1;

	for (int i = n - 2; i >= 0; i--) {
		dp[i] = 2 * dp[i + 1];
		while (!lower.empty() && a[i] < a[lower.top()]) {
			lower.pop();
		}
		if (!lower.empty()) {
			dp[i] -= dp[lower.top()];
			int curr = lower.top();
			while (curr != -1 && a[curr] < a[i]) {
				curr = maxEnd[curr];
			}
			if (curr != -1) {
				dp[i] += dp[curr];
			}
			else {
				dp[i] += 1;
			}
		}
		while (!upper.empty() && (a[i] >= a[upper.top()])) {
			upper.pop();
		}
		if (!upper.empty()) {
			maxEnd[i] = upper.top();
		}
		else {
			maxEnd[i] = -1;
		}
		lower.push(i);
		upper.push(i);
		dp[i] = (dp[i] + MOD) % MOD;
	}
	
	arrPrint(dp);
	print(dp[0]);
}
