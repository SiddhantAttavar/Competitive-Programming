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

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &d) {
	for (int v : graph[u]) {
		if (v != p) {
			d[v] = d[u] + 1;
			dfs(v, u, graph, d);
		}
	}
}

bool dfs2(int u, int p, int w, vector<vector<int>> &graph, vector<bool> &z) {
	z[u] = true;
	if (u == w) {
		return true;
	}
	for (int v : graph[u]) {
		if (v != p and dfs2(v, u, w, graph, z)) {
			return true;
		}
	}
	z[u] = false;
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> p(n), q(n);
		dfs(0, -1, graph, p);
		int x = max_element(p.begin(), p.end()) - p.begin();
		dfs(x, -1, graph, q);
		int y = max_element(q.begin(), q.end()) - q.begin();

		vector<bool> z(n, false);
		dfs2(x, -1, y, graph, z);

		if (accumulate(z.begin(), z.end(), 0ll) == n) {
			print(-1);
			continue;
		}

		int a = -1, b = x, c = -1;
		while (c == -1) {
			int e = -1;
			for (int d : graph[b]) {
				if (d == a) {
					continue;
				}
				if (z[d]) {
					e = d;
				}
				else {
					c = d;
					break;
				}
			}
			if (c == -1) {
				a = b;
				b = e;
			}
		}
		print(a + 1, b + 1, c + 1);
	}
}
