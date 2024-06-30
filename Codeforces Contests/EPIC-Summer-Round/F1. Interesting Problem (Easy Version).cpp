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

		vector<vector<int>> dp(n + 1, vector<int>(n + 3, 0));
		vector<vector<int>> p(n + 1, vector<int>(n + 3, n));
		for (int i = n - 1; i >= 0; i--) {
			for (int x = 0; x <= n; x += 2) {
				if ((i + 1 + x) > a[i] and (i + 1 + x - a[i]) % 2 == 0 and x >= 2) {
					p[i][x] = p[i][x - 2];
					dp[i][x] = dp[p[i][x]][x];
					continue;
				}

				dp[i][x] = dp[i + 1][x];
				if (i + 1 + x != a[i]) {
					p[i][x] = i;
					continue;
				}

				if (p[i + 1][x] == n) {
					p[i][x] = i;
					continue;
				}

				int u = p[i + 1][x] + 1;
				dp[i][x]++;
				if (u == n) {
					continue;
				}

				p[i][x] = p[u][x];
			}
		}

		int res = 0;
		int l = 0;
		for (int x = 0; x <= n; x += 2) {
			res += dp[l][x];
			if (p[l][x] == l) {
				break;
			}
			l = p[l][x];
		}

		print(res);
	}
}
