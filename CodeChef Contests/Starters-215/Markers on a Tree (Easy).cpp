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

int dfs(int u, int p, vector<vector<int>> &graph, vector<bool> &b) {
	int res = 0;
	for (int v : graph[u]) {
		if (v != p) {
			int x = dfs(v, u, graph, b);
			res += x + 2 * (x or b[v]);
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n, -1);
		vector<vector<int>> graph(n);
		rep(i, 1, n) {
			input(p[i]);
			p[i]--;
			graph[i].push_back(p[i]);
			graph[p[i]].push_back(i);
		}

		string s;
		input(s);
		vector<bool> b(n);
		rep(i, 0, n) {
			b[i] = s[i] == '1';
		}

		vector<int> v;
		int u = n - 1;
		while (u) {
			v.push_back(u);
			u = p[u];
		}

		int res = 1e18;
		for (int i : v) {
			graph[p[i]].erase(find(graph[p[i]].begin(), graph[p[i]].end(), i));
			graph[i].erase(find(graph[i].begin(), graph[i].end(), p[i]));
			res = min(res, dfs(0, -1, graph, b) + dfs(n - 1, -1, graph, b));
			graph[i].push_back(p[i]);
			graph[p[i]].push_back(i);
		}
		print(res);
	}
}
