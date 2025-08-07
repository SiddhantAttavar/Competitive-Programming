#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

vector<int> get_dists(vector<vector<pair<int, int>>> &graph, vector<int> v) {
	int n = graph.size();
	std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> d(n, 1e18);
	for (int i : v) {
		d[i] = 0;
		pq.push({0, i});
	}
	while (!pq.empty()) {
		auto [x, u] = pq.top();
		pq.pop();

		if (x > d[u]) {
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

bool check(int m, int s, int t, vector<vector<pair<int, int>>> &graph, vector<int> &d, vector<int> &a, vector<int> &b, vector<int> &g) {
	queue<int> q;
	vector<bool> l(d.size(), false);
	for (int i : g) {
		if (a[i] <= m) {
			l[i] = true;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto [v, w] : graph[u]) {
			if (!l[v] and d[u] + d[v] + w <= m) {
				l[v] = true;
				q.push(v);
			}
		}
	}
	for (int i : g) {
		if (b[i] <= m and l[i]) {
			return true;
		}
	}
	return a[t] <= m;
}

int32_t main() {
	setup();
	int n, m, k;
	input(n, m, k);

	vector<int> g(k);
	arrput(g);

	int s, t;
	input(s, t);
	s--;
	t--;
	rep(i, 0, k) {
		g[i]--;
	}

	vector<vector<pair<int, int>>> graph(n);
	rep(i, 0, m) {
		int u, v, w;
		input(u, v, w);

		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, w});
	}

	vector<int> d = get_dists(graph, g);
	vector<int> a = get_dists(graph, {s});
	vector<int> b = get_dists(graph, {t});
	int l = 0, r = a[t] - 1, res = a[t];
	while (l <= r) {
		int m = (l + r) / 2;
		if (check(m, s, t, graph, d, a, b, g)) {
			res = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	if (res == 1e18) {
		print(-1);
	}
	else {
		print(res);
	}
}
