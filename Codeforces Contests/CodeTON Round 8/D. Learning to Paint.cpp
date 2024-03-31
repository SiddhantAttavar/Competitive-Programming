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
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<vector<int>> a(n + 1, vector<int>(n, 0));
		range(i, 0, n) {
			range(j, i, n) {
				input(a[i][j]);
			}
		}

		vector<vector<int>> dp(n);
		bool flag = true;
		range(i, 0, n) {
			if (flag and (1 << (i + 1)) > k) {
				flag = false;
			}

			if (flag) {
				dp[i] = vector<int>(1 << (i + 1), 0);
			}
			else {
				dp[i] = vector<int>(k, 0);
			}
		}

		if (a[0][0] > 0) {
			dp[0][0] = a[0][0];
		}
		else if (dp[0].size() == 2) {
			dp[0][1] = a[0][0];
		}

		range(i, 1, n) {
			priority_queue<pair<int, int>> pq;
			pq.push({a[0][i], 0});
			pq.push({a[1][i], 1});
			range(j, 2, i + 2) {
				pq.push({dp[j - 2][0] + a[j][i], j});
			}

			vector<int> c(i, 1);
			range(l, 0, dp[i].size()) {
				int x, j;
				tie(x, j) = pq.top();
				pq.pop();

				dp[i][l] = x;

				if (j < 2 or c[j - 2] == dp[j - 2].size()) {
					continue;
				}

				pq.push({dp[j - 2][c[j - 2]] + a[j][i], j});
				c[j - 2]++;
				continue;
			}
		}

		arrPrint(dp[n - 1]);
	}
}
