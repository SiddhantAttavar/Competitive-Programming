#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = 998244353;

int32_t main() {
	setup();
	int n, k, x, m;
	input(n, k, x, m);

	vector<int> a(m);
	arrPut(a);

	vector<vector<int>> dp(n + 1, vector<int>(k + x, 0));
	for (int j : a) {
		dp[0][j]++;
	}
	range(i, 0, n) {
		range(j, 0, k + x - 1) {
			dp[i + 1][j] = dp[i][j + 1];
		}
		dp[i + 1][k - 1] = (dp[i + 1][k - 1] + dp[i][0]) % MOD;
		dp[i + 1][k + x - 1] = (dp[i + 1][k + x - 1] + dp[i][0]) % MOD;
	}

	int res = 0;
	range(j, 0, k + x) {
		res = (res + dp[n][j]) % MOD;
	}
	print(res);
}
