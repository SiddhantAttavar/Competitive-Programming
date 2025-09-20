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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool dfs(int u, vector<vector<int>> &graph, vector<int> &c, vector<bool> &vis) {
	vis[u] = true;
	for (int v : graph[u]) {
		if (c[v] != 0 and c[v] == c[u]) {
			return false;
		}
		c[v] = -c[u];
		if (!vis[v] and !dfs(v, graph, c, vis)) {
			return false;
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		vector<vector<int>> graph(n);
		vector<int> c(n, 0);
		bool flag = true;
		rep(i, 0, n) {
			if (s[i] == '1') {
				continue;
			}

			if (i > 0 and s[i - 1] == '1') {
				if (i == 1 or s[i - 2] == '1') {
					c[i] = 1;
				}
				else {
					graph[i].push_back(i - 2);
					graph[i - 2].push_back(i);
				}
			}
			if (i < n - 1 and s[i + 1] == '1') {
				if (i == n - 2 or s[i + 2] == '1') {
					if (c[i] == 1) {
						flag = false;
						break;
					}
					c[i] = -1;
				}
				else {
					graph[i].push_back(i + 2);
					graph[i + 2].push_back(i);
				}
			}
		}

		vector<bool> vis(n, false);
		rep(i, 0, n) {
			if (s[i] == '0' and !vis[i] and c[i] != 0 and !dfs(i, graph, c, vis)) {
				flag = false;
				break;
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
