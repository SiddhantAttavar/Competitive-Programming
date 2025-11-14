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

vector<int> get_dist(const vector<int> &l, vector<vector<pair<int, int>>> &graph) {
	vector<int> d(graph.size(), 1e18);
	std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int u : l) {
		d[u] = 0;
		pq.push({d[u], u});
	}
	while (!pq.empty()) {
		auto [x, u] = pq.top();
		pq.pop();

		if (x != d[u]) {
			continue;
		}

		for (auto [v, w] : graph[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
	return d;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<vector<pair<int, int>>> graph(n), ngraph(2 * n);
	rep(i, 0, m) {
		int u, v, w;
		input(u, v, w);

		graph[u].push_back({v, 2 * w});
		graph[v].push_back({u, 2 * w});

		ngraph[u].push_back({v, 2 * w});
		ngraph[v].push_back({u, 2 * w});
		ngraph[n + u].push_back({n + v, w});
		ngraph[n + v].push_back({n + u, w});
	}

	int k;
	input(k);
	vector<int> a(k);
	arrput(a);

	int q;
	input(q);
	vector<int> b(q);
	arrput(b);
	rep(i, 0, q) {
		ngraph[b[i]].push_back({n + b[i], 0});
	}

	int s, d;
	input(s, d);

	vector<int> x = get_dist({s}, graph), y = get_dist(a, ngraph);
	if (x[d] < min(y[d], y[n + d])) {
		print(x[d] / 2);
	}
	else {
		print(-1);
	}
}
