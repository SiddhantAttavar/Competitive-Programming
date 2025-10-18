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

vector<int> get_dist(int u, vector<vector<pair<int, int>>> &graph) {
	int n = graph.size();
	vector<int> d(n, 1e18);
	std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, u});
	d[u] = 0;
	while (!pq.empty()) {
		auto [x, u] = pq.top();
		pq.pop();

		if (x != d[u]) {
			continue;
		}

		for (auto [v, w] : graph[u]) {
			if (d[u] + w < d[v]) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
	return d;
}

int32_t main() {
	setup();

	double t, r;
	input(t, r);

	int n, m;
	input(n, m);

	vector<vector<pair<int, int>>> graph(n);
	rep(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	int k;
	input(k);

	vector<int> l(k);
	vector<double> p(k);
	vector<vector<int>> d(k);
	rep(i, 0, k) {
		input(l[i], p[i]);
		l[i]--;
		p[i] /= 100;
		d[i] = get_dist(l[i], graph);
	}

	vector<vector<double>> dp(k, vector<double>(1 << k, 1e18));
	for (int i = (1 << k) - 1; i >= 0; i--) {
		rep(u, 0, k) {
			if (!(i >> u & 1)) {
				continue;
			}
			if (d[u][n - 1] < 1e18) {
				dp[u][i] = min(dp[u][i], d[u][n - 1] * (p[u] / t + (1 - p[u]) / r));
			}

			int j = i ^ (1 << u);
			rep(v, 0, k) {
				if (i >> v & 1 and d[u][l[v]] < 1e18) {
					dp[v][j] = min(dp[v][j], p[v] * (dp[u][i] + d[u][l[v]] / t) + (1 - p[v]) * d[v][n - 1] / r);
				}
			}
		}
	}

	vector<int> v = get_dist(0, graph);
	if (v[n - 1] == 1e18) {
		print(-1);
		return 0;
	}

	double res = v[n - 1] / t;
	rep(i, 0, k) {
		if (v[l[i]] < 1e18) {
			res = min(res, dp[i][1 << i] + v[l[i]] / t);
		}
	}

	cout << fixed << setprecision(15);
	print(res);
}
