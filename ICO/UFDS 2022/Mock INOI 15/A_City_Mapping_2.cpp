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

vector<vector<int>> l;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> topo;

void dfs(int u) {
	visited[u]= true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	topo.push_back(u);
}

int32_t main() {
	setup();

	int n;
	input(n);

	l.resize(n, vector<int>(n, -1));
	graph.resize(n);
	range(i, 0, n) {
		range(j, 0, n) {
			input(l[i][j]);
			l[i][j]--;

			if (i != j) {
				if (l[i][j] == i) {
					graph[i].push_back(j);
				}
				if (l[i][j] == j) {
					graph[j].push_back(i);
				}
			}
		}
	}

	visited.resize(n, false);
	range(i, 0, n) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(topo.begin(), topo.end());

	vector<int> p(n, -1);
	range(i, 0, n) {
		for (int j = i - 1; j >= 0; j--) {
			if (l[topo[j]][topo[i]] == topo[j]) {
				p[topo[i]] = topo[j] + 1;
				break;
			}
		}
	}
	arrPrint(p);
}

