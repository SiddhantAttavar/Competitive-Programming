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

		map<string, vector<int>> g, w;
		range(i, 0, n) {
			string a, b;
			input(a, b);

			g[a].push_back(i);
			w[b].push_back(i);
		}

		vector<vector<int>> graph(n);
		for (pair<string, vector<int>> p : g) {
			range(i, 0, p.second.size()) {
				range(j, i + 1, p.second.size()) {
					graph[p.second[i]].push_back(p.second[j]);
					graph[p.second[j]].push_back(p.second[i]);
				}
			}
		}
		for (pair<string, vector<int>> p : w) {
			range(i, 0, p.second.size()) {
				range(j, i + 1, p.second.size()) {
					graph[p.second[i]].push_back(p.second[j]);
					graph[p.second[j]].push_back(p.second[i]);
				}
			}
		}

		vector<vector<int>> dp(n, vector<int>(1 << n, 0));
		range(i, 0, 1 << n) {
			range(u, 0, n) {
				if (((1 << u) & i) == 0) {
					continue;
				}

				range(v, 0, n) {
					dp[u][i] = max(dp[u][i], dp[v][i ^ (1 << u)]);
				}

				dp[u][i] = 1;
				for (int v : graph[u]) {
					if ((1 << v) & i) {
						dp[u][i] = max(dp[u][i], dp[v][i ^ (1 << u)] + 1);
					}
				}
			}
		}

		int res = 0;
		range(i, 0, n) {
			res = max(res, dp[i][(1 << n) - 1]);
		}
		print(n - res);
	}
}
