#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int s;
int n, m, k, g;
vector<vector<pair<int, int>>> graph, revGraph;

void dijkstrasAlgorithm(vector<vector<pair<int, int>>> &graph, vector<int> &dist, int k, int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, k});
	dist = vector<int>(n, (int) 1e9);
	dist[k] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		//print(u);
		pq.pop();
		if (u < k) {
			//continue;
		}
		for (pair<int, int> p : graph[u]) {
			int v, w;
			tie(v, w) = p;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
}

int32_t main() {
	setup();
	input(s);
	input(n, m, k, g);
	graph.resize(n);
	revGraph.resize(n);
	while (m--) {
		int u, v, w;
		input(u, v, w);
		graph[u - 1].push_back({v - 1, w});
		revGraph[v - 1].push_back({u - 1, w});
	}
	//print("Debug");
	
	vector<int> dist, revDist;
	dijkstrasAlgorithm(graph, dist, k, n);
	dijkstrasAlgorithm(revGraph, revDist, k, n);
	//print("Debug");
	//arrPrint(dist);
	//arrPrint(revDist);
	
	vector<pair<int, int>> distPair(n), revDistPair(n);
	range(i, 0, n) {
		distPair[i] = {dist[i] + revDist[i], i};
	}
	sort(distPair.begin(), distPair.end());
	
	int sum = 0;
	range(i, 0, k) {
		sum += dist[i] + revDist[i];
	}

	/*vector<vector<int>> dp(k, g);
	range(i, 0, g) {
		dp[0][i] = -1;
	}
	dp[0][0] = 0;
	range(i, 1, k) {
		range(j, 0, g) {
			if (j >= i) {
				dp[i][j] = -1;
				continue;
			}
			if (dp[i - 1][j] == -1) {
				dp[i][j] = dp[i - 1][j - 1] + ;
			}
			else {
				dp[i][j] = min(
					dp[i - 1][j - 1] + distPair[i].first,
					dp[i][j - 1] + distPair[i].first
				);
			}
		}
	}*/

	int res = 0;
	range(i, 0, k) {
		res += sum - dist[i] + revDist[i] * (k - 1);
	}
	print(res);
}