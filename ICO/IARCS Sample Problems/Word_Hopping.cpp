#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << (x) << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

vector<int> graph[100];
bool visited[100];
vector<int> nodes;
int dist[100];

void dfs(int u) {
	visited[u] = true;
	for (int v : graph[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
	nodes.push_back(u);
}

bool canHop(string &a, string &b) {
	int n = a.size();
	int m = b.size();

	if (n == m) {
		bool flag = false;
		range(i, 0, n) {
			if (a[i] != b[i]) {
				if (flag || a[i] > b[i]) {
					return false;
				}
				range(j, i + 1, n) {
					if (a[j] == b[i]) {
						flag = true;
					}
				}
				if (!flag) {
					return false;
				}
			}
		}
		return flag;
	}

	if (n == m + 1) {
		bool flag = false;
		range(i, 0, m) {
			if (a[i + flag] != b[i]) {
				if (flag) {
					return false;
				}
				flag = true;
				i--;
			}
		}
		return true;
	}

	return false;
}

int main() {
	setup();
	
	input(int, n);
	arrput(string, words, n);

	range(i, 0, n) {
		range(j, 0, n) {
			if (canHop(words[i], words[j])) {
				graph[i].push_back(j);
			}
		}
	}

	range(i, 0, n) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(nodes.begin(), nodes.end());

	int res = 0;
	range(i, 0, n) {
		fill(dist, dist + n, INT_MIN);
		dist[i] = 1;

		for (int u : nodes) {
			for (int v: graph[u]) {
				dist[v] = max(dist[v], dist[u] + 1);
			}
		}

		//cout << *max_element(dist, dist + n) << " ";
		res = max(res, *max_element(dist, dist + n));
	}

	print(res);
}