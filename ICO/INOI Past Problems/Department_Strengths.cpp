#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
int minNode, maxNode;

//To find all elements in a department
int dfs1(int u) {
	visited[u] = true;
	minNode = min(minNode, u);
	maxNode = max(maxNode, u);

	int res = 1;
	for (int v : graph[u]) {
		if (!visited[v]) {
			res += dfs1(v);
		}
	}
	return res;
}

//To find sum of all levels in a department
long long dfs2(int u, int p, int level) {
	long long res = level;
	for (int v : graph[u]) {
		if (v != p) {
			res += dfs2(v, u, level + 1);
		}
	}
	return res;
}

int main() {
	setup();
	input(int, tc); while (tc--) {
		//Input
		cin >> n >> m;
		visited = vector<bool>(n, false);
		graph = vector<vector<int>>(n);
		range(i, 0, m) {
			input(int, u);
			input(int, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		//Calculate Strengths
		long long strengthEven = 0;
		long long strengthOdd = 0;
		range(u, 0, n) 	{
			if (!visited[u]) {
				minNode = n;
				maxNode = -1;

				//New department
				if (dfs1(u) % 2 == 0) {
					//Type Even
					strengthEven += dfs2(minNode, -1, 1);
				}
				else {
					//Type Odd
					strengthOdd += dfs2(maxNode, -1, 1);
				}
			}
		}

		cout << strengthEven << " " << strengthOdd << endl;

		//Clear the graph for the next testcase
		visited.clear();
		graph.clear();
	}
}