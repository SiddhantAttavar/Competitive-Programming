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
vector<bool> visited;

bool dfs(int u, int t) {
	visited[u] = true;
	if (u == t) {
		return true;
	}

	for (int v : graph[u]) {
		if (!visited[v] && dfs(v, t)) {
			return true;
		}
	}

	return false;
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		string s, t;
		input(s);
		input(t);

		if (s.size() != t.size()) {
			print("NO");
			continue;
		}

		graph = vector<vector<int>>(26);

		int m; input(m);
		while (m--) {
			string str; input(str);
			graph[str[0] - 'a'].push_back(str[3] - 'a');
		}

		bool flag = true;
		range(i, 0, s.size()) {
			visited = vector<bool>(26, false);
			if (!dfs(s[i] - 'a', t[i] - 'a')) {
				flag = false;
				break;
			}
		}

		print((flag ? "YES" : "NO"));
	}
}