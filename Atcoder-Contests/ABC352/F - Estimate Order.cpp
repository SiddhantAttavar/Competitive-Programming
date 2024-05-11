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

void dfs(int u, vector<int> &d, vector<int> &comp, vector<vector<pair<int, int>>> &graph) {
	comp.push_back(u);
	for (pair<int, int> p : graph[u]) {
		int v, w;
		tie(v, w) = p;
		if (d[v] == 1e9) {
			d[v] = d[u] + w;
			dfs(v, d, comp, graph);
		}
	}
}

vector<vector<bool>> calc_dp(int n, vector<vector<int>> &comp, vector<int> &a) {
	int m = comp.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(1 << n, false));
	dp[0][0] = true;
	range(i, 0, m) {
		range(j, 0, 1 << n) {
			if (dp[i][j]) {
				continue;
			}

			int y = a[i];
			bool flag = false;
			range(k, 0, n) {
				if (y >= 1 << n) {
					break;
				}

				// print(i, j, k, y);
				if ((j & y) != y) {
					y <<= 1;
					continue;
				}

				if (dp[i][j ^ y]) {
					dp[i + 1][j] = true;
					// if (dp[i + 1][j]) {
					// 	dp[i + 1][j] = false;
					// 	break;
					// }
					// else {
					// 	dp[i + 1][j] = true;
					// }
				}
				y <<= 1;
			}
		}
	}

	return dp;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		graph[u - 1].push_back({v - 1, -w});
		graph[v - 1].push_back({u - 1, w});
	}

	vector<int> d(n, 1e9);
	vector<vector<int>> comp;
	range(i, 0, n) {
		if (d[i] != 1e9) {
			continue;
		}

		d[i] = 0;
		comp.push_back({});
		dfs(i, d, comp.back(), graph);
	}

	vector<int> a(comp.size(), 0);
	range(i, 0, (int) comp.size()) {
		int x = 1e9;
		for (int j : comp[i]) {
			x = min(x, d[j]);
		}

		for (int j : comp[i]) {
			d[j] -= x;
			a[i] |= 1 << d[j];
		}
	}

	vector<vector<bool>> pref_dp = calc_dp(n, comp, a);
	reverse(comp.begin(), comp.end());
	reverse(a.begin(), a.end());

	vector<vector<bool>> suff_dp = calc_dp(n, comp, a);
	reverse(comp.begin(), comp.end());
	reverse(a.begin(), a.end());
	reverse(suff_dp.begin(), suff_dp.end());

	// for (vector<bool> v : suff_dp) {
	// 	arrPrint(v);
	// }

	vector<int> res(n, -1);
	int o = (1 << n) - 1;
	range(i, 0, (int) comp.size()) {
		int x = -1;
		bool flag = true;
		range(j, 0, 1 << n) {
			int y = a[i];
			range(k, 0, n) {
				// print(i, j, k, y, o ^ j ^ y, pref_dp[i][j], suff_dp[i + 1][o ^ j ^ y]);
				if (y >= 1 << n) {
					break;
				}

				if (j & y) {
					y <<= 1;
					continue;
				}

				if (pref_dp[i][j] and suff_dp[i + 1][o ^ j ^ y]) {
					if (x != -1 and x != k) {
						flag = false;
						break;
					}
					x = k;
				}
				y <<= 1;
			}

			if (!flag) {
				break;
			}
		}

		if (!flag or x == -1) {
			continue;
		}

		for (int j : comp[i]) {
			res[j] = d[j] + x + 1;
		}
	}
	arrPrint(res);
}
