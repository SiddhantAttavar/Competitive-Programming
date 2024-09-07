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

	int n, k;
	input(n, k);

	vector<int> a(n);
	arrPut(a);

	int x = 0, y = 0;
	vector<int> dp(n, 0);
	map<int, int> m;
	range(i, 0, n) {
		x += a[i];

		dp[i] = (y + (x != k)) % MOD;
		if (m.count(x - k)) {
			dp[i] -= m[x - k];
			dp[i] += MOD;
			dp[i] %= MOD;
		}

		y += dp[i];
		y %= MOD;
		m[x] += dp[i];
		m[x] %= MOD;
	}

	print(dp[n - 1]);
}
