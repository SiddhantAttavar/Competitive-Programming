#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n;
vector<vector<int>> graph;
vector<int> a;

int dfs(int u, int prev) {
	for (int v : graph[u]) {
		if (v != prev) {
			a[u] += dfs(v, u);
		}
	}
	return a[u];
}

int main() {
	setup();
	cin >> n;
	
	graph = vector<vector<int>>(n);
	a = vector<int>(n, 1);
	range(i, 1, n) {
		input(int, p);
		graph[p - 1].push_back(i);
	}

	dfs(0, -1);

	for (int i : a) {
		cout << i - 1 << " ";
	}
	print("");
}
