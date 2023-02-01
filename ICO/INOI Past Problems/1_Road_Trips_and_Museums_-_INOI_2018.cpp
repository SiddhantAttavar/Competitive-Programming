#include <bits/stdc++.h>
#define range(var, start, end) for (int var = start; var < end; var++)
#define input(var) cin >> var
#define arrPut(arr) for (auto &var : arr) cin >> var;
#define print(var) cout << var << '\n'
#define arrPrint(arr) for (auto var : arr) {cout << var << ' ';} cout << '\n';
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int n, m, k;
vector<vector<int>> graph;
vector<int> a;
vector<bool> visited;

ll dfs(int u) {
	visited[u] = true;

	ll res = a[u];
	for (int v : graph[u]) {
		if (!visited[v]) {
			res += dfs(v);
		}
	}
	return res;
}

int main() {
	int tc; input(tc); while (tc--) {
		input(n);
		input(m);
		input(k);

		graph = vector<vector<int>>(n);
		visited = vector<bool>(n, false);
		a = vector<int>(n);

		while (m--) {
			int u, v;
			input(u);
			input(v);

			u--;
			v--;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		arrPut(a);

		vector<ll> museums;
		range(i, 0, n) {
			if (!visited[i]) {
				museums.push_back(dfs(i));
			}
		}

		if (museums.size() < k) {
			print(-1);
			continue;
		}

		sort(museums.begin(), museums.end());
		ll res = 0;
		range(i, 0, k / 2) {
			res += museums[i] + museums[museums.size() - i - 1];
		}
		if (k % 2 == 1) {
			res += museums[museums.size() - k / 2 - 1];
		}

		print(res);
	}
}
