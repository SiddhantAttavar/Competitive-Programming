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

	int n, m;
	input(n, m);

	vector<vector<int>> a(n, vector<int>(m));
	for (vector<int> &v : a) {
		arrPut(v);
	}

	vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
	range(i, 0, n) {
		range(j, 0, m) {
			pref[i + 1][j + 1] = pref[i][j + 1] + pref[i + 1][j] - pref[i][j] + a[i][j];
		}
	}

	vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n, vector<int>(m, 0))));
	range(l, 1, n + 1) {
		range(r, 1, m + 1) {
			range(i, 0, n - l + 1) {
				range(j, 0, m - r + 1) {
					int x = i + l - 1, y = j + r - 1;
					dp[l][r][i][j] = 1e9;
					int c = pref[x + 1][y + 1] - pref[i][y + 1] - pref[x + 1][j] + pref[i][j];
					range(k, i, x) {
						dp[l][r][i][j] = min(dp[l][r][i][j], dp[k - i + 1][r][i][j] + dp[x - k][r][k + 1][j] + c);
					}
					range(k, j, y) {
						dp[l][r][i][j] = min(dp[l][r][i][j], dp[l][k - j + 1][i][j] + dp[l][y - k][i][k + 1] + c);
					}
					if (dp[l][r][i][j] == 1e9) {
						dp[l][r][i][j] = 0;
					}
				}
			}
		}
	}

	print(dp[n][m][0][0]);
}
