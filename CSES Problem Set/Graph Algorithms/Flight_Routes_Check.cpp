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

vector<vector<int>> gFront, gBack;
vector<bool> vFront, vBack;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited) {
	visited[u] = true;

	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v, graph, visited);
		}
	}
}

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	gFront.resize(n);
	gBack.resize(n);

	vFront = vector<bool>(n, false);
	vBack = vector<bool>(n, false);

	range(i, 0, m) {
		int u, v;
		input(u);
		input(v);

		gFront[u - 1].push_back(v - 1);
		gBack[v - 1].push_back(u - 1);
	}

	dfs(0, gFront, vFront);
	dfs(0, gBack, vBack);

	range(i, 1, n) {
		if (!vFront[i] || !vBack[i]) {
			print("NO");
			if (!vFront[i]) {
				print("1 " << i + 1);
			}
			else {
				print(i + 1 << " 1");
			}
			return 0;
		}
	}

	print("YES");
}