#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(2 * n), rev_graph(2 * n);
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(n + v - 1);
		graph[n + u - 1].push_back(v - 1);
		rev_graph[n + v - 1].push_back(u - 1);
		rev_graph[v - 1].push_back(n + u - 1);
	}

	vector<bool> a(2 * n, true);
	vector<int> c(2 * n);
	queue<int> q;
	rep(i, 0, 2 * n) {
		c[i] = graph[i].size();
		if (c[i] == 0) {
			a[i] = false;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u < n) {
			for (int v : rev_graph[u]) {
				a[v] = false;
				q.push(v);
			}
		}
		else {
			for (int v : rev_graph[u]) {
				c[v]--;
				if (c[v] == 0) {
					a[v] = false;
					q.push(v);
				}
			}
		}
	}

	vector<bool> b(2 * n, false);
	rep(i, 0, 2 * n) {
		c[i] = graph[i].size();
		if (c[i] == 0 and i < n) {
			b[i] = true;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u < n) {
			for (int v : rev_graph[u]) {
				b[v] = true;
				q.push(v);
			}
		}
		else {
			for (int v : rev_graph[u]) {
				c[v]--;
				if (c[v] == 0) {
					b[v] = true;
					q.push(v);
				}
			}
		}
	}

	rep(i, 0, n) {
		if (a[i]) {
			cout << 'D';
		}
		else if (b[i]) {
			cout << 'L';
		}
		else {
			cout << 'W';
		}
	}
	cout << endl;
	rep(i, n, 2 * n) {
		if (a[i]) {
			cout << 'D';
		}
		else if (b[i]) {
			cout << 'W';
		}
		else {
			cout << 'L';
		}
	}
	cout << endl;
}
