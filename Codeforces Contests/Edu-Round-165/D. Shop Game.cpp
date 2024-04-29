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
		int n, k;
		input(n, k);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		if (k == 0) {
			int x = 0;
			range(i, 0, n) {
				x += max(0ll, b[i] - a[i]);
			}
			print(x);
			continue;
		}

		vector<pair<int, int>> c;
		range(i, 0, n) {
			if (b[i] > a[i]) {
				c.push_back({b[i], i});
			}
		}
		sort(c.begin(), c.end());

		if (c.size() < k) {
			print(0);
			continue;
		}
		
		vector<pair<int, int>> dp(c.size());
		vector<vector<int>> par(n, vector<int>(20, -1));
		int m = 0;
		range(i, 0, k) {
			m -= a[c[i].second];
			par[i][0] = i - 1;
			range(j, 1, 20) {
				if (par[i][j - 1] == -1) {
					break;
				}
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}

		dp[k - 1] = {m, k - 1};
		range(i, k, n) {
			dp[i] = dp[i - 1];

			par[i][0] = dp[i - 1].second;
			range(j, 1, 20) {
				if (par[i][j - 1] == -1) {
					break;
				}
				par[i][j] = par[par[i][j - 1]][j - 1];
			}

			int u = i;
			for (int j = 19; j >= 0; j--) {
				if ((1 << j) & k) {
					u = par[u][j];
				}
			}
			print(u);
			cout.flush();

			if (b[u] > a[i]) {
				dp[i] = {dp[i - 1].first + b[u] - a[i], i - 1};
			}
		}

		print(max(0ll, dp.back().first));
	}
}
