#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

int main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> graph[n];
	int dist[n] = {0};
	fill(dist + 1, dist + n, -1);
	pair<int, int> edges[m];
	
	range(i, 0, m) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
		edges[i] = {u - 1, v - 1};
	}

	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	for (pair<int, int> p : edges) {
		int u, v;
		tie(u, v) = p;
		if (dist[u] < dist[v]) {
			print(v + 1, u + 1);
		}
		else {
			print(u + 1, v + 1);
		}
	}
}