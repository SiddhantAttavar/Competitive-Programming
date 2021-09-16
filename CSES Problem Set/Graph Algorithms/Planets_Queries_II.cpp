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

int n, q, currTime;
vector<vector<int>> prevN, graph;
vector<int> nextN, comp, timeIn, timeOut, cycleEnd, depth, cycleSize;
vector<bool> v2, compDone, inCycle;

void dfs1(int u, int c) {
	comp[u] = c;

	for (int v : graph[u]) {
		if (comp[v] == -1) {
			dfs1(v, c);
		}
	}
}

int dfs2(int u) {
	v2[u] = true;

	if (v2[nextN[u]]) {
		return u;
	}

	return dfs2(nextN[u]);
}

void dfs3(int u, int d) {
	depth[u] = d;
	timeIn[u] = currTime;
	currTime++;

	for (int v : prevN[u]) {
		if (depth[v] == -1) {
			dfs3(v, d - 1);
		}
	}

	currTime++;
	timeOut[u] = currTime;
}

int main() {
	setup();

	input(n);
	input(q);

	graph.resize(n);
	prevN.resize(n);
	nextN.resize(n);
	timeIn.resize(n);
	timeOut.resize(n);

	comp = vector<int>(n, -1);
	depth = vector<int>(n, -1);
	v2 = vector<bool>(n, false);
	inCycle = vector<bool>(n, false);

	range(i, 0, n) {
		int j;
		input(j);
		j--;

		nextN[i] = j;
		prevN[j].push_back(i);
		graph[i].push_back(j);
		graph[j].push_back(i);
	}

	int currComp = 0;
	range(i, 0, n) {
		if (comp[i] == -1) {
			dfs1(i, currComp);
			currComp++;
		}
	}

	compDone = vector<bool>(currComp, false);
	cycleSize = vector<int>(currComp, 0);
	range(i, 0, n) {
		if (prevN[i].size() == 0 && !compDone[comp[i]]) {
			compDone[comp[i]] = true;
			int cycleEnd = dfs2(i);

			int curr = cycleEnd;
			do {
				inCycle[curr] = true;
				curr = nextN[curr];
				cycleSize[comp[i]]++;
			} while (curr != cycleEnd);

			dfs3(cycleEnd, n);
		}
	}

	range(i, 0, n) {
		if (!compDone[comp[i]]) {
			compDone[comp[i]] = true;
			int cycleEnd = dfs2(i);

			int curr = cycleEnd;
			do {
				inCycle[curr] = true;
				curr = nextN[curr];
				cycleSize[comp[i]]++;
			} while (curr != cycleEnd);

			dfs3(cycleEnd, n);
		}
	}

	while (q--) {
		int a, b;
		input(a);
		input(b);

		if (a == b) {
			print(0);
			continue;
		}

		a--;
		b--;

		if (comp[a] != comp[b]) {
			print(-1);
			continue;
		}

		if (inCycle[a] && inCycle[b]) {
			print((depth[b] - depth[a] + cycleSize[comp[a]]) % cycleSize[comp[a]]);
			continue;
		}

		if (timeIn[a] > timeIn[b] == timeOut[a] > timeOut[b]) {
			print(-1);
			continue;
		}

		if (depth[a] > depth[b]) {
			print(-1);
			continue;
		}

		print(depth[b] - depth[a]);
	}
}