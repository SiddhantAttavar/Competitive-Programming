#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << endl;}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << endl;
#define int long long
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n, m, k;
vector<int> c, t;
vector<vector<pair<int, int>>> graph;
vector<int> topo;
vector<vector<bool>> reach;

void dfs(int u) {
	for (pair<int, int> p : graph[u]) {
		dfs(p.first);
	}
	topo.push_back(u);
}

void dfs2(int u, int s) {
	reach[s][u] = true;
	for (pair<int, int> p : graph[u]) {
		dfs2(p.first, s);
	}
}

int32_t main() {
	setup();
		
	input(n, m, k);

	c.resize(n);
	t.resize(n);
	graph.resize(n);

	arrPut(c);
	arrPut(t);
	range(i, 0, m) {
		int u, v, w;
		input(u, v, w);
		graph[v].push_back({u, w});
	}

	vector<int> topo;
	topo.push_back(0);
	int u = 0;
	while (graph[u].size()) {
		topo.push_back(graph[u][0].first);
		u = graph[u][0].first;
	}

	vector<int> d(n);
	range(i, 1, n) {
		d[topo[i]] = d[topo[i - 1]] + graph[topo[i - 1]][0].second;
	}

	vector<int> dp(n, 1e9);
	dp[0] = 0;
	range(i, 1, n) {
		range(j, 0, i) {
			int x = topo[i];
			int y = topo[j];

			dp[x] = min(
				dp[x],
				dp[y] + t[y] + c[x] * (k - d[y])
			);
		}
	}
	range(i, 1, n) {
		cout << dp[i] << ' ';
	}
	cout << endl;

	/**
	priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
	vector<int> d(n, -1);
	d[0] = 0;
	pq.push({0, 0});
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (pair<int, int> p : graph[u]) {
			int v, w;
			tie(v, w) = p;

			int x = max(d[u], w);
			if (x > d[v]) {
				d[v] = x;
				pq.push({x, v});
			}
		}
	}

	dfs(0);
	reverse(topo.begin(), topo.end());

	reach.resize(n, vector<bool>(n));
	range(i, 0, n) {
		dfs2(i, i);
	}

	vector<int> dp(n, 1e9);
	dp[0] = 0;
	range(i, 1, n) {
		range(j, 0, i) {
			int x = topo[i];
			int y = topo[j];

			if (reach[y][x]) {
				dp[x] = min(
					dp[x],
					dp[y] + t[y] + c[x] * (k - d[y])
				);
			}
		}
	}

	range(i, 1, n) {
		cout << dp[i] << ' ';
	}
	cout << endl;
	**/
}
