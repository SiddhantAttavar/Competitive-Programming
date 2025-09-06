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

void dfs(int u, int p, int &c, vector<vector<int>> &graph, vector<int> &d, vector<vector<int>> &par, vector<pair<int, int>> &t, vector<vector<int>> &l) {
	c++;
	t[u].first = c;
	l[d[u]].push_back(c);
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		d[v] = d[u] + 1;
		par[v][0] = u;
		rep(i, 1, 20) {
			if (par[v][i - 1] == -1) {
				break;
			}
			par[v][i] = par[par[v][i - 1]][i - 1];
		}
		dfs(v, u, c, graph, d, par, t, l);
	}
	t[u].second = c;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> graph(n + 1);
	rep(i, 0, n) {
		int p;
		input(p);

		if (p == 0) {
			p = n + 1;
		}
		graph[p - 1].push_back(i);
	}

	vector<int> d(n + 1, 0);
	vector<pair<int, int>> t(n + 1);
	vector<vector<int>> par(n + 1, vector<int>(20, -1));
	vector<vector<int>> l(n + 1);
	int c = 0;
	d[n] = 0;
	dfs(n, -1, c, graph, d, par, t, l);

	int m;
	input(m);
	while (m--) {
		int v, p;
		input(v, p);

		v--;
		int h = d[v];

		if (h - 1 < p) {
			cout << "0 ";
			continue;
		}

		int u = v;
		rep(i, 0, 20) {
			if (p & (1 << i)) {
				u = par[u][i];
			}
		}

		cout << (upper_bound(l[h].begin(), l[h].end(), t[u].second) - lower_bound(l[h].begin(), l[h].end(), t[u].first) - 1) << ' ';
	}
	cout << endl;
}
