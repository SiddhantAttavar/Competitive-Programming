#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

vector<int> dist(vector<set<int>> &graph, int u) {
	int n = graph.size();
	vector<bool> visited(n);
	queue<int> q;
	q.push(u);
	visited[u] = true;
	vector<int> res(n);
	res[u] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (!visited[v]) {
				visited[v] = true;
				res[v] = res[u] + 1;
				q.push(v);
			}
		}
	}

	return res;
}

int32_t main() {
	setup();
	
	int n, m, s, t;
	input(n, m, s, t);
	
	s--;
	t--;

	vector<set<int>> graph(n);
	range(i, 0, m) {
		int u, v;
		input(u, v);
		graph[u - 1].insert(v - 1);
		graph[v - 1].insert(u - 1);
	}

	vector<int> distS = dist(graph, s);
	vector<int> distT = dist(graph, t);
	// arrPrint(distS);
	// arrPrint(distT);

	int res = 0;
	range(i, 0, n) {
		range(j, i + 1, n) {
			res += !graph[i].count(j) and min(distS[i] + distT[j], distS[j] + distT[i]) + 1 >= distS[t];
		}
	}
	print(res);
}
