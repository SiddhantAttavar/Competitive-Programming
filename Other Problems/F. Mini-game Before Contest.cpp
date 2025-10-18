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

void dfs(int u, int i, vector<vector<int>> &graph, vector<vector<int>> &d, vector<string> &c, string &t, vector<vector<bool>> &vis) {
	vis[u][i] = true;
	int j = (i + 5) % 6;
	for (int v : graph[u]) {
		if (vis[v][j]) {
			continue;
		}
		if ((t[j] == t[i]) ^ (c[u][i] == t[i])) {
			d[v][j]--;
			if (!d[v][j]) {
				c[v][j] = t[j] ^ 'A' ^ 'B';
				dfs(v, j, graph, d, c, t, vis);
			}
		}
		else {
			c[v][j] = t[j];
			dfs(v, j, graph, d, c, t, vis);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vector<int>> graph(n);
		vector<vector<int>> d(n, vector<int>(6, 0));
		rep(i, 0, m) {
			int u, v;
			input(u, v);

			graph[v - 1].push_back(u - 1);
			rep(j, 0, 6) {
				d[u - 1][j]++;
			}
		}

		string s, t;
		input(s, t);

		rep(i, 0, 6) {
			if (t[i] == '0') {
				t[i] = s[i];
			}
			else {
				t[i] = s[i] ^ 'A' ^ 'B';
			}
		}

		vector<string> c(n, string(6, 'D'));
		vector<vector<bool>> vis(n, vector<bool>(6, false));
		rep(i, 0, n) {
			rep(j, 0, 6) {
				if (!d[i][j] and !vis[i][j]) {
					c[i][j] = s[j] ^ 'A' ^ 'B';
					dfs(i, j, graph, d, c, t, vis);
				}
			}
		}

		rep(i, 0, n) {
			cout << c[i][0];
		}
		cout << endl;
	}
}
