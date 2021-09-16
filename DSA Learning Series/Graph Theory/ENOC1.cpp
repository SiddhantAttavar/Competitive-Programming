#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<vector<int>> graph;
vector<int> dist;
vector<int> parent;
vector<int> a;

void dfs(int u, int p) {
	parent[u] = p;
	for (int v : graph[u]) {
		if (v != p) {
			dist[v] = dist[u] + 1;
			dfs(v, u);
		}
	}
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, q;
		input(n);
		input(q);

		graph = vector<vector<int>>(n);
		dist.resize(n);
		parent.resize(n);
		a.resize(n);

		arrPut(a);
		range(i, 0, n - 1) {
			int u, v;
			input(u);
			input(v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		dist[0] = 0;
		dfs(0, -1);

		while (q--) {
			int u, v;
			input(u);
			input(v);

			u--;
			v--;

			if (dist[u] < dist[v]) {
				swap(u, v);
			}

			int res = 0;
			while (dist[u] > dist[v]) {
				res ^= a[u];
				u = parent[u];
			}

			while (u != v) {
				res ^= a[u] ^ a[v];
				u = parent[u];
				v = parent[v];
			}

			print((res ^ a[u]));
		}
	}
}