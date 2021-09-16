#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const long long INF = 1e15;

int main() {
	setup();
	
	input(int, m);
	input(int, a);
	input(int, b);

	unordered_map<int, vector<pair<int, int>>> graph;
	range(i, 0, m) {
		input(int, u);
		input(int, w);
		input(int, v);
		if (graph.find(u) == graph.end()) {
			graph[u] = vector<pair<int, int>>();
		}
		if (graph.find(v) == graph.end()) {
			graph[v] = vector<pair<int, int>>();
		}
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	unordered_map<int, long long> distance;
	unordered_map<int, bool> completed;
	for (pair<int, vector<pair<int, int>>> p : graph) {
		if (p.first == a) {
			distance[a] = 0;
			pq.push({0, a});
		}
		else {
			distance[p.first] = INF;
			pq.push({INF, p.first});
		}
		completed[p.first] = false;
	}

	range(i, 0, graph.size()) {
		int u = pq.top().second;
		pq.pop();
		completed[u] = true;

		for (pair<int, int> p : graph[u]) {
			if ((distance[u] + p.second) < distance[p.first]) {
				distance[p.first] = distance[u] + p.second;
				pq.push({distance[u] + p.second, p.first});
			}
		}
	}

	if (distance.find(b) == distance.end() || distance[b] == INF) {
		print("NO");
	}
	else {
		print("YES");
		print(distance[b]);
	}
}