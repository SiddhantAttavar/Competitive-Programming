#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, m, k;
vector<vector<int>> graph;
vector<int> a;
vector<bool> visited;

long long dfs(int u) {
	long long res = a[u];
	visited[u] = true;
	for (int v : graph[u]) {	
		if (!visited[v]) {
			res += dfs(v);
		}
	}
	return res;
}

int main() {
	setup();
	input(int, tc); while (tc--) {
		cin >> n >> m >> k;

		graph = vector<vector<int>>(n);
		a = vector<int>(n);
		visited = vector<bool>(n, false);
		range(i, 0, m) {
			input(int, u);
			input(int, v);
			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}
		range(i, 0, n) {
			cin >> a[i];
		}

		vector<long long> museums;
		range(i, 0, n) {
			if (!visited[i]) {
				museums.push_back(dfs(i));
			}
		}

		if (museums.size() < k) {
			print(-1);
		}
		else {
			sort(museums.begin(), museums.end());
			long long res = 0;
			range(i, 0, k / 2) {
				res += museums[i] + museums[museums.size() - i - 1];
			}
			if (k % 2 == 1) {
				res += museums[museums.size() - k / 2 - 1];
			}
			print(res);
		}
	}
}