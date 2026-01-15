#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

void dfs(int u, int p, vector<vi> &graph, vector<vector<bool>> &dp) {
	dp[u] = {true, false, false};
	for (int v : graph[u]) {
		if (v != p) {
			dfs(v, u, graph, dp);
			dp[u] = {
				(dp[u][0] and dp[v][0]) or (dp[u][1] and dp[v][2]) or (dp[u][2] and dp[v][1]),
				(dp[u][0] and dp[v][1]) or (dp[u][1] and dp[v][0]) or (dp[u][2] and dp[v][2]),
				(dp[u][0] and dp[v][2]) or (dp[u][1] and dp[v][1]) or (dp[u][2] and dp[v][0])
			};
		}
	}
	dp[u][1] = true;
	if (sz(graph[u]) == 1 and u != 0) {
		dp[u] = {false, true, false};
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vi> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			u--;
			v--;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<vector<bool>> dp(n, vector<bool>(3));
		dfs(0, -1, graph, dp);
		if (dp[0][0]) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
