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

void dfs(int u, vector<vector<int>> &graph, vector<int> &d, vector<bool> &c, vector<bool> &a) {
	for (int v : graph[u]) {
		if (c[u]) {
			d[v]--;
			if (d[v] == 0 and !a[v]) {
				c[v] = false;
				dfs(v, graph, d, c, a);
			}
		}
		else {
			d[v]++;
			if (d[v] == 1 and !a[v]) {
				c[v] = true;
				dfs(v, graph, d, c, a);
			}
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, q;
		input(n, m, q);

		vector<vector<int>> graph(2 * n);
		vector<int> d(2 * n, 0);
		vector<bool> c(2 * n, false), a(2 * n, false);
		rep(i, 0, m) {
			int u, v;
			input(u, v);

			graph[v + n - 1].push_back(u - 1);
			graph[v - 1].push_back(u + n - 1);
			d[u - 1]++;
		}
		rep(i, 0, n) {
			c[i] = true;
		}

		while (q--) {
			int o, u;
			input(o, u);

			u--;
			if (o == 1) {
				a[u] = true;
				a[u + n] = true;

				if (c[u]) {
					c[u] = false;
					dfs(u, graph, d, c, a);
				}
				if (!c[u + n]) {
					c[u + n] = true;
					dfs(u + n, graph, d, c, a);
				}
			}
			else if (c[u]) {
				print("YES");
			}
			else {
				print("NO");
			}
		}
	}
}
