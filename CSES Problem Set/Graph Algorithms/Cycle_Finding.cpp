#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<vector<int>> graph;
vector<bool> visited;

int dfs(int u) {
	if (visited[u]) {
		return 0;
	}
	visited[u] = true;
	int res = 1;
	for (int v : graph[u]) {
		res += dfs(v);
	}
	return res;
}

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	tuple<int, int, int> edges[m];
	graph.resize(n);
	visited = vector<bool>(n, false);

	range(i, 0, m) {
		int u, v, w;
		input(u);
		input(v);
		input(w);

		edges[i] = {u - 1, v - 1, w};
		graph[u - 1].push_back(v - 1);
	}

	ll distance[n];
	fill(distance, distance + n, 1e15);

	int parent[n];
	fill(parent, parent + n, -1);

	int cycleStart = -1;
	range(i, 0, n) {
		if (visited[i]) {
			continue;
		}
		int compSize = dfs(i);
		distance[i] = 0;

		if (n < 1000) {
			compSize = n;
		}

		range(j, 0, compSize - 1) {
			for (tuple<int, int, int> t : edges) {
				int u, v, w; tie(u, v, w) = t;
				if ((distance[u] + w) < distance[v]) {
					distance[v] = distance[u] + w;
					parent[v] = u;
				}
			}
		}

		for (tuple<int, int, int> t : edges) {
			int u, v, w; tie(u, v, w) = t;
			if ((distance[u] + w) < distance[v]) {
				parent[v] = u;
				cycleStart = u;
				break;
			}
		}

		if (cycleStart != -1) {
			break;
		}
	}

	if (cycleStart == -1) {
		print("NO");
		return 0;
	}

	print("YES");

	range(i, 0, n) {
		cycleStart = parent[cycleStart];
	}

	vector<int> cycle;
	int curr = cycleStart;
	do {
		cycle.push_back(curr + 1);
		curr = parent[curr];
	} while (curr != cycleStart);

	reverse(cycle.begin(), cycle.end());
	cout << cycleStart + 1 << " ";
	arrPrint(cycle);
}