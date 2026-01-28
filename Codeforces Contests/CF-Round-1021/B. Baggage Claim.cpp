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

void dfs(int u, int m, int &s, int &x, int &e, vector<vi> &graph, vector<bool> &vis, vector<bool> &c) {
	vis[u] = true;
	s++;
	x += !c[u];
	e += sz(graph[u]);
	for (int v : graph[u]) {
		if (!vis[v]) {
			dfs(v, m, s, x, e, graph, vis, c);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		vi x(k + 1), y(k + 1);
		rep(i, 0, k + 1) {
			input(x[i], y[i]);
			x[i]--;
			y[i]--;
		}

		vector<bool> c(n * m, false);
		rep(i, 0, k + 1) {
			c[x[i] * m + y[i]] = true;
		}
		vector<vi> graph(n * m);
		int res = 1;
		rep(i, 0, k) {
			if (abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]) != 2) {
				res = 0;
				break;
			}

			if (x[i] == x[i + 1] or y[i] == y[i + 1]) {
				int p = (x[i] + x[i + 1]) / 2, q = (y[i] + y[i + 1]) / 2;
				if (c[p * m + q]) {
					res = 0;
					break;
				}
				c[p * m + q] = true;
			}
			else {
				int p = x[i] * m + y[i + 1], q = x[i + 1] * m + y[i];
				graph[p].push_back(q);
				graph[q].push_back(p);
			}
		}
		
		vector<bool> v(n * m, false);
		rep(i, 0, n * m) {
			if (graph[i].empty() or v[i]) {
				continue;
			}

			int s = 0, x = 0, e = 0;
			dfs(i, m, s, x, e, graph, v, c);
			e /= 2;

			if (x < s) {
				if (x < s - 1 or e > s - 1) {
					res = 0;
					break;
				}
			}
			else {
				if (e > s) {
					res = 0;
					break;
				}
				if (e == s) {
					res = (res * 2) % MOD;
					continue;
				}
				res = (res * s) % MOD;
			}
		}
		print(res);
	}
}
