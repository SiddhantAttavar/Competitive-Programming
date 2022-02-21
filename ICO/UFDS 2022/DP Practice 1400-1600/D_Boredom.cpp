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
	
	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);
	sort(a.begin(), a.end());

	vector<int> dp(n);
	vector<int> maxDp(n);
	dp[0] = a[0];
	maxDp[0] = a[0];
	range(i, 1, n) {
		int j = lower_bound(a.begin(), a.end(), a[i] - 1) - a.begin();
		j--;
		if (a[i] == a[i - 1]) {
			dp[i] = a[i] + dp[i - 1];
		}
		else {
			if (j >= 0) {
				dp[i] = a[i] + maxDp[j];
			}
			else {
				dp[i] = a[i];
			}
		}
		maxDp[i] = max(maxDp[i - 1], dp[i]);
	}
	print(maxDp[n - 1]);
}
