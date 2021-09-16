#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, m;
vector<int> graph[300];
bool visited[300];

void dfs(int u) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main() {
	setup();
	
	//Input
	cin >> n >> m;
	range(i, 0, m) {
		input(int, u);
		input(int, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> critical;
	//Check for each node
	range(i, 0, n) {
		fill(visited, visited + n, false);
		visited[i] = true;
		dfs((i + 1) % n);
		range(j, 0, n) {
			if (!visited[j]) {
				critical.push_back(i);
				break;
			}
		}
	}

	sort(critical.begin(), critical.end());
	print(critical.size());
	for (int i : critical) {
		print(i + 1);
	}
}