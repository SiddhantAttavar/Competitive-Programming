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

	//Input
	input(int, n);
	input(int, m);
	vector<int> graph[n];
	range(i, 0, m) {
		input(int, u);
		input(int, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	input(int, s);
	input(int, t);

	int res = 0;

	bool visited[n];
	fill(visited, visited + n, false);
	visited[s - 1] = true;

	queue<pair<int, int>> q;
	q.push({s - 1, 0});
	while (!q.empty()) {
		int u, d;
		tie(u, d) = q.front();
		q.pop();

		if (u == t - 1) {
			res = d;
			break;
		}

		for (int v : graph[u]) {
			if (!visited[v]) {
				visited[v] = true;
				q.push({v, d + 1});
			}
		}
	}

	print(res);
}