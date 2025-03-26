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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> t(n - 1);
	arrput(t);
	
	int N = 1e5;
	vector<vector<int>> dp(n, vector<int>(N + 1, 1e15));
	rep(i, 0, N + 1) {
		dp[0][i] = i;
	}
	rep(i, 0, n - 1) {
		rep(j, t[i], N + 1) {
			dp[i + 1][j] = min(dp[i + 1][j - 1] + 1, dp[i][j - t[i]] + t[i]);
		}
		int y = 1e15;
		for (int j = N - t[i]; j >= 0; j--) {
			y = min(y, dp[i][j + t[i]]);
			dp[i + 1][j] = min(dp[i + 1][j], y);
		}
	}
	print(*min_element(dp[n - 1].begin(), dp[n - 1].end()));
}
