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

const int MAX_N = 1e5;
bool visited[MAX_N];
vector<int> graph[MAX_N];
vector<int> cycle;
int cycleStart = -1;

bool dfs(int u, int p) {
	visited[u] = true;

	for (int v : graph[u]) {
		if (visited[v]) {
			//Cycle
			if (v != p && cycleStart == -1) {
				cycleStart = v;
				cycle.push_back(v + 1);
				cycle.push_back(u + 1);
				return true;
			}
		}
		else {
			if (dfs(v, u)) {
				cycle.push_back(u + 1);
				if (u != cycleStart) {
					return true;
				}
				return false;
			}
		}
	}

	return false;
}

int main() {
	setup();
	
	int n, m;
	input(n);
	input(m);

	range(i, 0, m) {
		int u, v;
		input(u);
		input(v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	bool flag = false;
	range(i, 0, n) {
		if (!visited[i]) {
			dfs(i, -1);
			if (cycle.size() > 0) {
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		print(cycle.size());
		arrPrint(cycle);
	}
	else {
		print("IMPOSSIBLE");
	}
}