#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int n, q, root;
const int MAX_N = 1e5;
int parent[MAX_N];
vector<int> graph[MAX_N];
bool hasBoulder[MAX_N] = {false};
int minSubTree[MAX_N];
int subTreeSize[MAX_N];
int subTreeFilled[MAX_N];

void dfs(int u) {
	minSubTree[u] = u;
	subTreeSize[u] = 1;
	for (int v : graph[u]) {
		dfs(v);
		minSubTree[u] = min(minSubTree[u], minSubTree[v]);
		subTreeSize[u] += subTreeSize[v];
	}
}

int query1(int u, int q) {
	subTreeFilled[u] += q;
	for (int v : graph[u]) {
		int temp = subTreeSize[v] - subTreeFilled[v];
		if (temp >= q) {
			return query1(v, q);
		}
		else if (temp > 0) {
			query1(v, temp);
			q -= temp;
		}
	}
	hasBoulder[u] = true;
	return u;
}

int query2(int u) {
	if (u == root || !hasBoulder[parent[u]]) {
		hasBoulder[u] = false;
		subTreeFilled[u]--;
		while (u != root) {
			u = parent[u];
			subTreeFilled[u]--;
		}
		return 0;
	}
	return query2(parent[u]) + 1;
}

int main() {
	setup();
	input(n, q);

	range(i, 0, n) {
		input(parent[i]);
		parent[i]--;
		graph[parent[i]].push_back(i);
	}

	range(i, 0, n) {
		if (parent[i] == -1) {
			root = i;
			break;
		}
	}

	dfs(root);

	range(i, 0, n) {
		sort(graph[i].begin(), graph[i].end(), [](int a, int b) {
			return minSubTree[a] < minSubTree[b];
		});
	}

	while (q--) {
		int op, u; input(op, u);

		if (op == 1) {
			print(query1(root, u) + 1);
		}
		else {
			print(query2(u - 1));
		}
	}
}