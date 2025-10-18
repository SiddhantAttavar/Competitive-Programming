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

void solve(vector<vector<tuple<int, int, int>>> &x, vector<vector<int>> &s, vector<vector<int>> &graph, vector<int> &res) {
	int n = graph.size();
	vector<vector<int>> dist = graph;
	rep(k, 0, x.size()) {
		for (int i : s[k]) {
			rep(u, 0, n) {
				rep(v, 0, n) {
					dist[u][v] = min(dist[u][v], dist[u][i] + dist[i][v]);
				}
			}
		}
		for (auto [u, v, i] : x[k]) {
			if (dist[u][v] == 1e18) {
				res[i] = -1;
			}
			else {
				res[i] = dist[u][v];
			}
		}
	}
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> c(n);
	arrput(c);

	vector<vector<int>> graph(n, vector<int>(n, 1e18));
	rep(i, 0, n) {
		graph[i][i] = 0;
	}
	rep(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		graph[u - 1][v - 1] = w;
		graph[v - 1][u - 1] = w;
	}

	map<int, int> a;
	for (int i : c) {
		a[i] = 0;
	}

	int i = 0;
	for (auto [k, v] : a) {
		a[k] = i + 1;
		i++;
	}

	vector<vector<int>> s(a.size() + 2);
	rep(i, 0, n) {
		s[a[c[i]]].push_back(i);
	}

	vector<vector<tuple<int, int, int>>> x(a.size() + 1), y(a.size() + 1);
	int q;
	input(q);
	rep(i, 0, q) {
		int s, e, k, t;
		input(s, e, k, t);

		s--;
		e--;
		k = min(k, (int) a.size());
		if (t == 0) {
			x[k].push_back({s, e, i});
		}
		else {
			y[k].push_back({s, e, i});
		}
	}

	vector<int> res(q);
	solve(x, s, graph, res);
	reverse(s.begin(), s.end());
	solve(y, s, graph, res);

	for (int i : res) {
		print(i);
	}
}
