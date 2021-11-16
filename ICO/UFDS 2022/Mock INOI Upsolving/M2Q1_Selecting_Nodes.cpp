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

void dfs(int u, int curr, vector<vector<pair<int, int>>> &graph, vector<int> &dist) {
	dist[u] = curr;
	for (pair<int, int> p : graph[u]) {
		int v, w; tie(v, w) = p;
		if (dist[v] == -1) {
			dfs(v, curr + w, graph, dist);
		}
	}
}

int32_t main() {
	setup();
	int n, a, b; input(n, a, b);
	a--; b--;
	vector<vector<pair<int, int>>> graph(n);
	range(i, 0, n - 1) {
		int x, y, w; input(x, y, w);
		x--; y--;
		graph[x].push_back({y, w});
		graph[y].push_back({x, w});
	}

	vector<int> distA(n, -1), distB(n, -1);
	dfs(a, 0, graph, distA);
	dfs(b, 0, graph, distB);

	vector<pair<int, int>> diff(n, {0, 0});
	range(i, 0, n) {
		diff[i] = {distA[i] + distB[i], i};
	}
	sort(diff.begin(), diff.end());
	
	//int l = 0, r = n - 1;
	int r = n - 1;
	int res = 0;
	vector<bool> visited(n, false);
	range(i, 0, n) {
		if (i % 2 == 0) {
			while (visited[diff[r].second]) {
				r--;
			}
			res += distA[diff[r].second];
			visited[diff[r].second] = true;
		}
		else {
			/*while (distB[diff[l].second] == (int) 1e9 or visited[diff[l].second]) {
				l++;
			}
			res -= distB[diff[l].second];
			visited[diff[l].second] = true;*/
			while (visited[diff[r].second]) {
				r--;
			}
			res -= distB[diff[r].second];
			visited[diff[r].second] = true;
		}
	}
	print(res);
}