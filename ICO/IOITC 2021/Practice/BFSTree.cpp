#include <bits/stdc++.h>
using namespace std;
inline void input() {}; template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define print(msg) cout << msg << endl
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m; input(n, m);
		
		vector<int> graph[n];
		unordered_set<int> neighbours[n];
		range(i, 0, m) {
			int u, v; input(u, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
			neighbours[u - 1].insert(v - 1);
			neighbours[v - 1].insert(u - 1);
		}

		vector<int> tree[n];
		range(i, 1, n) {
			int p; input(p);
			tree[p].push_back(i);
		}

		int dist[n] = {0};
		fill(dist + 1, dist + n, -1);

		int parent[n] = {-1};
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : graph[u]) {
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					parent[v] = u;
					q.push(v);
				}
			}
		}

		bool flag = true;
		q.push(0);
		bool visited[n] = {true};
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : tree[u]) {
				if (dist[v] - dist[u] != 1 || visited[v]) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
			for (int v : graph[u]) {
				if (!visited[v]) {
					visited[v] = true;
					q.push(v);
				}
			}
		}

		print((flag ? "YES" : "NO"));
	}
}