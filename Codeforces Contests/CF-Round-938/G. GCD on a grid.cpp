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
		int n, m;
		input(n, m);

		vector<vector<int>> a(n, vector<int>(m));
		range(i, 0, n) {
			arrPut(a[i]);
		}

		vector<int> f;
		for (int i = 1; i * i <= a[0][0]; i++) {
			if (a[0][0] % i == 0) {
				f.push_back(i);
				if (i * i != a[0][0]) {
					f.push_back(a[0][0] / i);
				}
			}
		}
		sort(f.begin(), f.end());

		vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(f.size(), false)));
		range(i, 0, n) {
			range(j, 0, m) {
				range(k, 0, f.size()) {
					if (a[i][j] % f[k] == 0) {
						dp[i][j][k] = (i and dp[i - 1][j][k]) or (j and dp[i][j - 1][k]) or (!i and !j);
					}
				}
			}
		}

		int res = 1;
		range(k, 1, f.size()) {
			if (dp[n - 1][m - 1][k]) {
				res = f[k];
			}
		}

		print(res);
	}
}
