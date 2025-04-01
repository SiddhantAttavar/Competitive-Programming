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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs(int x, int y, vector<vector<vector<pair<int, int>>>> &graph, vector<vector<bool>> &vis) {
	vis[x][y] = true;
	for (pair<int, int> p : graph[x][y]) {
		if (!vis[p.first][p.second]) {
			dfs(p.first, p.second, graph, vis);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<string> a(n);
		arrput(a);

		vector<vector<vector<pair<int, int>>>> graph(n + 2, vector<vector<pair<int, int>>>(m + 2));
		rep(i, 0, n) {
			rep(j, 0, m) {
				if (a[i][j] == 'U') {
					graph[i][j + 1].push_back({i + 1, j + 1});
				}
				else if (a[i][j] == 'D') {
					graph[i + 2][j + 1].push_back({i + 1, j + 1});
				}
				else if (a[i][j] == 'L') {
					graph[i + 1][j].push_back({i + 1, j + 1});
				}
				else if (a[i][j] == 'R') {
					graph[i + 1][j + 2].push_back({i + 1, j + 1});
				}
			}
		}

		vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));
		rep(i, 0, n) {
			if (!vis[i + 1][0]) {
				dfs(i + 1, 0, graph, vis);
			}
			if (!vis[i + 1][m + 1]) {
				dfs(i + 1, m + 1, graph, vis);
			}
		}
		rep(j, 0, m) {
			if (!vis[0][j + 1]) {
				dfs(0, j + 1, graph, vis);
			}
			if (!vis[n + 1][j + 1]) {
				dfs(n + 1, j + 1, graph, vis);
			}
		}

		int res = 0;
		rep(i, 0, n) {
			rep(j, 0, m) {
				if (a[i][j] == '?') {
					res += !vis[i][j + 1] or !vis[i + 2][j + 1] or !vis[i + 1][j] or !vis[i + 1][j + 2];
				}
				else {
					res += !vis[i + 1][j + 1];
				}
			}
		}
		print(res);
	}
}
