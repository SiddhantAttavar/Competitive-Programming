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

int n;
vector<vector<int>> graph;
vector<int> prevN, nextN;
vector<int> comp;
vector<bool> cycleDone;
vector<int> a;
vector<bool> visited;

int compSize = 0;

void dfs(int u) {
	comp[u] = compSize;

	for (int v : graph[u]) {
		if (comp[v] == -1) {
			dfs(v);
		}
	}
}

int size(int u) {
	if (a[u] != -1) {
		return a[u];
	}
	return a[u] = size(nextN[u]) + 1;
}

int main() {
	setup();
	
	int n;
	input(n);

	comp = vector<int>(n, -1);
	graph.resize(n);
	visited = vector<bool>(n, false);
	prevN = vector<int>(n, 0);
	nextN.resize(n);
	a = vector<int>(n, -1);

	range(i, 0, n) {
		int j;
		input(j);
		j--;

		prevN[j]++;
		nextN[i] = j;
		graph[i].push_back(j);
		graph[j].push_back(i);
	}

	range(i, 0, n) {
		if (comp[i] == -1) {
			dfs(i);
			compSize++;
		}
	}

	cycleDone = vector<bool>(compSize, false);

	range(i, 0, n) {
		if (prevN[i] == 0 && !cycleDone[comp[i]]) {
			cycleDone[comp[i]] = true;
			int curr = i;

			while (!visited[curr]) {
				visited[curr] = true;
				curr = nextN[curr];
			}

			int cycleStart = curr;

			int cycleSize = 0;

			do {
				cycleSize++;
				curr = nextN[curr];
			}  while (curr != cycleStart);

			do {
				a[curr] = cycleSize;
				curr = nextN[curr];
			}  while (curr != cycleStart);
		}
	}

	range(i, 0, n) {
		if (!cycleDone[comp[i]]) {
			cycleDone[comp[i]] = true;
			int curr = i;

			int cycleSize = 0;
			while (!visited[curr]) {
				visited[curr] = true;
				cycleSize++;
				curr = nextN[curr];
			}

			int cycleStart = curr;

			do {
				a[curr] = cycleSize;
				curr = nextN[curr];
			}  while (curr != cycleStart);
		}
	}

	range(i, 0, n) {
		if (prevN[i] == 0) {
			size(i);
		}
	}

	arrPrint(a);
}