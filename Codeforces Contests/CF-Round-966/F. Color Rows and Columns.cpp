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
	int N = 1e4;
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), b(n);
		range(i, 0, n) {
			input(a[i], b[i]);
		}

		int x = 0, y = 0;
		range(i, 0, n) {
			x += a[i] + b[i];
			y += a[i] * b[i];
		}
		if (x == k) {
			print(y);
			continue;
		}

		if (x < k) {
			print(-1);
			continue;
		}

		int res = y;
		range(i, 0, n) {
			vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
			dp[0][0] = 0;
			range(j, 0, n) {
				range(l, 0, k + 1) {
					dp[j + 1][l] = dp[j][l];
				}

				if (i == j) {
					continue;
				}

				range(l, a[j] + b[j], k + 1) {
					dp[j + 1][l] = min(dp[j][l], dp[j][l - a[j] - b[j]] + a[j] * b[j]);
				}
			}

			res = min(res, dp[n][k]);
			int x = a[i], y = b[i], z = 0;
			range(j, 1, a[i] + b[i] + 1) {
				if (k < j) {
					break;
				}

				if (x > y) {
					swap(x, y);
				}

				z += x;
				y--;
				res = min(res, dp[n][k - j] + z);
			}
		}

		print(res);
	}
}
