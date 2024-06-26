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
 
	vector<int> a(n);
	arrPut(a);
	sort(a.begin(), a.end());
 
	vector<pair<int, int>> dp(1 << n, {1e18, 1e18});
	dp[0] = {0, 0};
	range(i, 1, 1 << n) {
		range(j, 0, n) {
			if ((i & (1 << j)) == 0) {
				continue;
			}

			pair<int, int> c = dp[i ^ (1 << j)];
			if (c.second + a[j] <= x) {
				c.second += a[j];
			}
			else {
				c.first++;
				c.second = a[j];
			}

			dp[i] = min(dp[i], c);
		}
	}
 
	print(dp.back().first + (dp.back().second > 0));
}
