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

void dfs(int u, vector<vector<int>> &graph, vector<int> &p, vector<int> &d) {
	for (int v : graph[u]) {
		if (v != p[u]) {
			p[v] = u;
			d[v] = d[u] + 1;
			dfs(v, graph, p, d);
		}
	}
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

		vector<int> p(n, -1), d(n, 0);
		dfs(0, graph, p, d);

		vector<int> v(n), c(n, 0);
		rep(i, 0, n) {
			v[d[i]]++;
			if (p[i] != -1) {
				c[p[i]]++;
			}
		}

		int res = *max_element(v.begin(), v.end());
		rep(i, 0, n) {
			if (c[i] == res) {
				res++;
				break;
			}
		}
		print(res);
	}
}
