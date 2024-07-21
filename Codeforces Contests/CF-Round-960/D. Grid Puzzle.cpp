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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> p(n + 1, 0);
		range(i, 0, n) {
			p[i + 1] = p[i] + (a[i] == 4 or a[i] == 3);
		}

		vector<int> dp(n + 1, 0);
		int x = -1;
		range(i, 0, n) {
			dp[i + 1] = dp[i] + (a[i] > 0);
			if (a[i] > 2) {
				continue;
			}

			if (x == -1) {
				x = i;
				continue;
			}

			if ((i - x) % 2 == 0) {
				x = i;
				continue;
			}

			if (p[i] - p[x] != (i - x - 1)) {
				x = i;
				continue;
			}

			dp[i + 1] = min(dp[i + 1], dp[x] + (i - x));
			// print(i, x);
			x = i;
		}
		print(dp[n]);
	}
}
