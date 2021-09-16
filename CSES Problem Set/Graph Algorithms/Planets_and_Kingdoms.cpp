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
vector<int> timeIn, low;
vector<bool> inStack;
vector<int> res;
stack<int> s;

int currTime = 0;
int curr = 0;

void dfs(int u, int p) {
	visited[u] = true;
	currTime++;
	timeIn[u] = currTime;
	low[u] = currTime;
	inStack[u] = true;
	s.push(u);

	for (int v : graph[u]) {
		if (visited[v]) {
			if (inStack[v]) {
				//It is a back edge
				low[u] = min(low[u], timeIn[v]);
			}
		}
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
	}

	if (low[u] != timeIn[u]) {
		return;
	}

	curr++;
	int w = 0;
	do {
		w = s.top();
		s.pop();
		res[w] = curr;
		inStack[w] = false;
	} while (w != u);
}

int main() {
	setup();

	int n, m;
	input(n);
	input(m);
	
	graph.resize(n);
	visited = vector<bool>(n, false);
	timeIn.resize(n);
	low = vector<int>(n, INT_MAX);
	inStack = vector<bool>(n, false);
	res.resize(n);

	while (m--) {
		int a, b;
		input(a);
		input(b);

		a--;
		b--;

		graph[a].push_back(b);
	}

	range(i, 0, n) {
		if (!visited[i]) {
			dfs(i, -1);
		}
	}

	print(curr);
	arrPrint(res);
}