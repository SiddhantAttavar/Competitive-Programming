#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int N = 1000000;
	vector<int> dp(N + 1, 1e9);
	dp[0] = 0;
	vector<int> v = {1, 3, 6, 10, 15};
	range(i, 1, N + 1) {
		for (int j : v) {
			if (i >= j) {
				dp[i] = min(dp[i], dp[i - j] + 1);
			}
		}
	}

	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int res = 0;
		if (n > N) {
			res += (n - N + 14) / 15;
			n -= 15 * res;
			assert(n <= N);
		}

		print(res + dp[n]);
	}
}
