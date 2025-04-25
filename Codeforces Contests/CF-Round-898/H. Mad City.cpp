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

void dfs(int u, vector<vector<int>> &graph, vector<int> &visited, vector<int> &stack, vector<bool> &inCycle) {
	visited[u] = 0;
	stack.push_back(u);
	for (int v : graph[u]) {
		// print(u, v);
		if (visited[v] == -1) {
			dfs(v, graph, visited, stack, inCycle);
		}
		else if (visited[v] == 0 and v != stack[(int) stack.size() - 2]) {
			for (int i = (int) stack.size() - 1; i >= 0; i--) {
				inCycle[stack[i]] = true;
				if (stack[i] == v) {
					break;
				}
			}
		}
	}
	stack.pop_back();
	visited[u] = 1;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, a, b;
		input(n, a, b);
		a--;
		b--;

		vector<vector<int>> graph(n);
		range(i, 0, n) {
			int u, v;
			input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		vector<int> visited(n, -1);
		vector<int> stack;
		vector<bool> inCycle(n, false);
		range(i, 0, n) {
			if (visited[i] == -1) {
				dfs(i, graph, visited, stack, inCycle);
			}
		}

		vector<int> d1(n, 1e9), d2(n, 1e9);
		queue<int> q;
		fill(visited.begin(), visited.end(), false);
		visited[a] = true;
		d1[a] = 0;
		q.push(a);
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : graph[u]) {
				if (!visited[v]) {
					d1[v] = d1[u] + 1;
					visited[v] = true;
					q.push(v);
				}
			}
		}

		fill(visited.begin(), visited.end(), false);
		visited[b] = true;
		d2[b] = 0;
		q.push(b);
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v : graph[u]) {
				if (!visited[v]) {
					d2[v] = d2[u] + 1;
					visited[v] = true;
					q.push(v);
				}
			}
		}

		// arrPrint(d1);
		// arrPrint(d2);
		// arrPrint(inCycle);

		bool flag = d1[b] == (int) 1e9;
		range(i, 0, n) {
			if (inCycle[i] and (d1[i] > d2[i])) {
				flag = true;
				break;
			}
		}

		print(flag ? "YES" : "NO");
	}
}
