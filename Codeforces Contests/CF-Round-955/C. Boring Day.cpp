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
		int n, l, r;
		input(n, l, r);

		vector<int> a(n);
		arrPut(a);

		vector<int> pref(n + 1, 0);
		range(i, 0, n) {
			pref[i + 1] = pref[i] + a[i];
		}

		vector<int> dp(n + 1, 0);
		range(i, 0, n) {
			dp[i + 1] = dp[i];
			int j = upper_bound(pref.begin(), pref.end(), pref[i + 1] - l) - pref.begin() - 1;
			// print(i, j);
			if (j >= 0 and pref[i + 1] - pref[j] <= r) {
				dp[i + 1] = max(dp[i], dp[j] + 1);
			}
		}
		// arrPrint(dp);

		print(dp[n]);
	}
}
