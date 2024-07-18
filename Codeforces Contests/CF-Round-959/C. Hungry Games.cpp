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
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);

		vector<int> a(n);
		arrPut(a);

		vector<int> s(n + 1, 0), dp(n + 1, 0);
		for (int i = n - 1; i >= 0; i--) {
			s[i] = s[i + 1] + a[i];

			int l = i, r = n - 1, u = n;
			while (l <= r) {
				int m = (l + r) / 2;
				if (s[i] - s[m + 1] > x) {
					u = m;
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}

			dp[i] = u - i;
			if (u < n and s[i] - s[u + 1] > x) {
				dp[i] += dp[u + 1];
			}
		}

		print(accumulate(dp.begin(), dp.end(), 0ll));
	}
}
