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
#define int ll

const int MOD = 1e9 + 7;
const int MAX_N = 1e5;

vector<int> graph[MAX_N];

int a[MAX_N];
int res[MAX_N];
int minSubTree[MAX_N];
int subTreeDistSum[MAX_N];
int subTreeSize[MAX_N];
int subTreeMinDistSum[MAX_N];

void init(int u, int p) {
	subTreeDistSum[u] = 0;
	minSubTree[u] = u;
	subTreeSize[u] = 1;
	for (int v : graph[u]) {
		if (v != p) {
			init(v, u);
			subTreeSize[u] += subTreeSize[v];
			subTreeDistSum[u] = (subTreeSize[v] + subTreeDistSum[v]) % MOD;
			if (a[minSubTree[u]] > a[minSubTree[v]]) {
				minSubTree[u] = minSubTree[v];
			}
		}
	}
}

void subTreeDfs(int u, int p) {
	subTreeMinDistSum[u] = 0;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		subTreeDfs(v, u);

		if (a[u] < a[minSubTree[v]]) {
			subTreeMinDistSum[u] = (subTreeMinDistSum[u] + subTreeDistSum[v]) % MOD;
		}
		else {
			res[u] = (res[u] + res[v] + subTreeMinDistSum[v]) % MOD;
			subTreeMinDistSum[u] = (subTreeMinDistSum[u] + subTreeMinDistSum[v]) % MOD;
		}
	}
}

void parentDfs(int u, int p) {
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		if (a[v] > a[minSubTree[u]]) {
			res[v] = (res[v] + res[u] + subTreeMinDistSum[u] - subTreeMinDistSum[v] + MOD) % MOD;
			minSubTree[v] = minSubTree[u];
		}
		else {
			subTreeMinDistSum[v] = (subTreeSize[0] - subTreeDistSum[v] + subTreeMinDistSum[v] + MOD) % MOD;
		}

		parentDfs(v, u);
	}
}

signed main() {
	setup();
	int n; input(n);

	range(i, 0, n - 1) {
		int u, v;
		input(u, v);
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	arrPut(a);

	init(0, -1);
	subTreeDfs(0, -1);
	parentDfs(0, -1);

	int final = 0;
	for (int i : res) {
		final = (final + i) % MOD;
	}
	print(final);
}