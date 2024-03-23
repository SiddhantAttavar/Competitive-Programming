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

	int n, m, k;
	input(n, m, k);

	if (k & 1) {
		range(i, 0, n) {
			range(j, 0, m) {
				cout << "-1 ";
			}
			cout << endl;
		}
		return 0;
	}

	vector<vector<pair<int, int>>> graph(n * m);
	range(i, 0, n) {
		range(j, 0, m - 1) {
			int w;
			input(w);
			graph[i * m + j].push_back({i * m + j + 1, w});
			graph[i * m + j + 1].push_back({i * m + j, w});
		}
	}
	range(i, 0, n - 1) {
		range(j, 0, m) {
			int w;
			input(w);
			graph[i * m + j].push_back({(i + 1) * m + j, w});
			graph[(i + 1) * m + j].push_back({i * m + j, w});
		}
	}

	vector<vector<int>> dp(n * m, vector<int>(k / 2 + 1, 1e9));
	range(u, 0, n * m) {
		dp[u][0] = 0;
	}

	range(i, 1, k / 2 + 1) {
		range(u, 0, n * m) {
			for (pair<int, int> p : graph[u]) {
				dp[u][i] = min(dp[u][i], dp[p.first][i - 1] + p.second);
			}
		}
	}

	range(i, 0, n) {
		range(j, 0, m) {
			cout << 2 * dp[i * m + j][k / 2] << ' ';
		}
		cout << endl;
	}
}
