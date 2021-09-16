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

	vector<pair<int, int>> graph[n];
	range(i, 0, m) {
		input(int, u);
		input(int, v);
		input(int, w);
		graph[u - 1].push_back({v - 1, w});
	}

	long long distance[n] = {0};
	fill(distance + 1, distance + n, LONG_LONG_MAX);
	
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, 0});
	range(i, 1, n) {
		pq.push({LONG_LONG_MAX, i});
	}

	while (!pq.empty()) {
		pair<long long, int> p = pq.top();
		pq.pop();
		int u = p.second;
		if (p.first != distance[u]) {
			continue;
		}

		for (pair<int, int> v : graph[u]) {
			if (distance[v.first] > (distance[u] + v.second)) {
				pq.push({distance[u] + v.second, v.first});
				distance[v.first] = distance[u] + v.second;
			}
		}
	}

	for (long long i : distance) {
		cout << i << " ";
	}
}