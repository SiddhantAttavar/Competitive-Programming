#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int main() {
	setup();
	input(int, n);
	input(int, m);
	
	vector<int> graph[n + 1];
	range(i, 0, m) {
		input(int, u);
		input(int, v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int prev[n + 1];
	prev[1] = -1;
	bool visited[n + 1];
	fill(visited + 1, visited + n + 1, false);
	visited[1] = true;
	queue<int> q;
	q.push(1);
	
	bool flag = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == n) {
			flag = false;
			break;
		}

		for (int v : graph[u]) {
			if (!visited[v]) {
				visited[v] = true;
				prev[v] = u;
				q.push(v);
			}
		}
	}

	if (flag) {
		print("IMPOSSIBLE");
		return 0;
	}

	vector<int> path;
	int curr = n;
	while (curr != -1) {
		path.push_back(curr);
		curr = prev[curr];
	}
	print(path.size());
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
}