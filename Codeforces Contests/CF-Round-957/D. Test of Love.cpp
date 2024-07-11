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
		int n, m, k;
		input(n, m, k);

		string s;
		input(s);
		s += 'L';

		vector<int> a(n);
		int x = n;
		for (int i = n - 1; i >= 0; i--) {
			a[i] = x;
			if (s[i] == 'W') {
				x = i;
			}
		}

		vector<int> dp(n + 1, k + 1);
		if (s[0] == 'W') {
			dp[0] = 1;
		}
		range(i, 0, min(m, n + 1)) {
			if (s[i] != 'C') {
				dp[i] = s[i] == 'W';
			}
		}

		range(i, 0, n) {
			if (dp[i] > k) {
				continue;
			}

			if (s[i] == 'W') {
				if (s[i + 1] != 'C') {
					dp[i + 1] = min(dp[i + 1], dp[i] + (s[i + 1] == 'W'));
				}
				continue;
			}

			range(j, i + 1, min(n + 1, i + m + 1)) {
				if (s[j] != 'C') {
					dp[j] = min(dp[j], dp[i] + (s[j] == 'W'));
				}
			}
		}

		if (dp[n] <= k) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
