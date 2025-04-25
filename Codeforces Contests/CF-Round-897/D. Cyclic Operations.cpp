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

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<vector<int>> &comp) {
	visited[u] = true;
	comp.back().push_back(u);
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v, graph, visited, comp);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> b(n);
		arrPut(b);
		
		vector<vector<int>> graph(n);
		range(i, 0, n) {
			b[i]--;
			graph[i].push_back(b[i]);
			graph[b[i]].push_back(i);
		}

		if (k == 1) {
			bool flag = true;
			range(i, 0, n) {
				if (b[i] != i) {
					flag = false;
					break;
				}
			}

			print(flag ? "YES" : "NO");
			continue;
		}

		vector<bool> visited(n, false);
		vector<vector<int>> comp;
		range(i, 0, n) {
			if (!visited[i]) {
				comp.push_back({});
				dfs(i, graph, visited, comp);
			}
		}

		bool flag = true;
		fill(visited.begin(), visited.end(), false);
		range(i, 0, n) {
			if (visited[i]) {
				continue;
			}

			int u = i;
			set<int> inStack;
			while (!visited[u]) {
				visited[u] = true;
				inStack.insert(u);
				u = b[u];
			}

			if (!inStack.count(u)) {
				continue;
			}

			int v = u;
			int c = 1;
			while (b[v] != u) {
				v = b[v];
				c++;
			}

			if (c != k) {
				flag = false;
				break;
			}
		}

		print(flag ? "YES" : "NO");
	}
}
