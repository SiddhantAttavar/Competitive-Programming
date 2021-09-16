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
vector<int> team;

bool dfs(int u, int t) {
	team[u] = t;
	for (int v : graph[u]) {
		if (team[v] == 0) {
			if (!dfs(v, t % 2 + 1)) {
				return false;
			}
		}
		else if (team[v] == t) {
			return false;
		}
	}
	return true;
}

int main() {
	setup();
	cin >> n >> m;
	graph = vector<vector<int>>(n);
	team = vector<int>(n, 0);
	
	range(i, 0, m) {
		input(int, u);
		input(int, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	range(i, 0, n) {
		if (team[i] == 0 && !dfs(i, 1)) {
			print("IMPOSSIBLE");
			return 0;
		}
	}

	for (int i : team) {
		cout << i << " ";
	}
}