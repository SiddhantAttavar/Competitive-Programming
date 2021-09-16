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
	input(int, k);

	vector<int> graph[n];
	int outDegree[n] = {0};
	range(i, 0, m) {
		input(int, u);
		input(int, v);
		outDegree[u - 1]++;
		outDegree[v - 1]++;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	queue<int> q;
	bool visited[n] = {0};
	range(i, 0, n) {
		if (outDegree[i] < k) {
			q.push(i);
			visited[i] = true;
		}
	}

	int res = n;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		res--;
		
		for (int v : graph[u]) {
			outDegree[v]--;
			if (!visited[v] && outDegree[v] < k) {
				q.push(v);
				visited[v] = true;
			}
		}
	}

	if (res == 0) {
		print("NO");
	}
	else {
		print("YES");
		print(res);
	}
}