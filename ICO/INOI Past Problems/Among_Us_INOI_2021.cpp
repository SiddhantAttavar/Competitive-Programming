#include <bits/stdc++.h>
#define range(var, start, end) for (int var = start; var < end; var++)
#define input(var) cin >> var
#define arrPut(arr) for (auto &var : arr) {cin >> var;}
#define print(msg) cout << msg << endl
#define arrPrint(arr) for (auto msg : arr) {cout << msg << " ";} cout << endl;
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

int n, q;
vector<vector<pair<int, bool>>> graph;
vector<int> color;
vector<int> currComp;
vector<bool> visited;

bool dfs(int u, int c) {
	visited[u] = true;
	color[u] = c;
	currComp.push_back(u);

	for (pair<int, bool> p : graph[u]) {
		int v; bool b;
		tie(v, b) = p;

		int finColor = b ? c : -c;
		if (color[v] == 0) {
			//New node
			if (!dfs(v, finColor)) {
				return false;
			}
		}
		else {
			//We have visited this node before
			if (color[v] != finColor) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		input(n);
		input(q);

		currComp.clear();
		color = vector<int>(n, 0);
		visited = vector<bool>(n, false);
		graph = vector<vector<pair<int, bool>>>(n);

		range(i, 0, q) {
			int u, v, w;
			input(w);
			input(u);
			input(v);

			graph[u - 1].push_back({v - 1, w == 2});
			graph[v - 1].push_back({u - 1, w == 2});
		}

		int res = 0;
		range(i, 0, n) {
			if (visited[i]) {
				continue;
			}

			currComp.clear();

			int curr = res;
			bool flag = dfs(i, -1);
			if (flag) {
				for (int u : currComp) {
					curr += color[u] == -1;
				}
			}

			//Doesn't work if i is a parasite
			for (int u : currComp) {
				color[u] = 0;
			}

			currComp.clear();

			if (dfs(i, 1)) {
				for (int u : currComp) {
					res += color[u] == -1;
				}
			}
			else if (!flag) {
				//Doesn't work if i is a human either
				res = -1;
				break;
			}

			res = max(res, curr);
		}

		print(res);
	}
}