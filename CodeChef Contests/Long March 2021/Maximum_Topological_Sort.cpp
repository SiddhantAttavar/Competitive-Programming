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
#define int ll

int n, k;
vector<vector<int>> graph;
vector<ll> c;
vector<int> subTreeSize;
vector<ll> factorial(1e6 + 1), invFactorial(1e6 + 1);

int modPow(ll a, int b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

int modDiv(ll a, int b) {
	return (a * modPow(b, MOD - 2)) % MOD;
}

int size(int u, int p) {
	subTreeSize[u] = 0;

	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		subTreeSize[u] += size(v, u) + 1;
	}

	return subTreeSize[u];
}

ll dfs1(int u, int p) {
	c[u] = 1;

	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}
		c[u] = (c[u] * dfs1(v, u)) % MOD;
		c[u] = (c[u] * invFactorial[subTreeSize[v] + 1]) % MOD;
	}

	return (c[u] * factorial[subTreeSize[u]]) % MOD;
}

void dfs2(int u, int p) {
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		c[v] = modDiv((c[u] * (subTreeSize[v] + 1)), n - subTreeSize[v] - 1);
		dfs2(v, u);
	}
}

signed main() {
	setup();

	//Precompute factorials and invFactorials
	factorial[0] = 1;
	range(i, 1, 1e6 + 1) {
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}

	invFactorial[0] = 1;
	invFactorial[1] = 1;
	range(i, 0, 1e6 + 1) {
		invFactorial[i] = modPow(factorial[i], MOD - 2);
	}

	int tc; input(tc); while (tc--) {
		int k;
		input(n);
		input(k);

		graph = vector<vector<int>>(n);
		c.resize(n);
		subTreeSize.resize(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u);
			input(v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		size(0, -1);
		dfs1(0, -1);
		dfs2(0, -1);

		int fin[n];
		range(i, 0, n) {
			fin[i] = (c[i] * factorial[n - 1]) % MOD;
		}

		int last = 0, secondLast = 1;
		if (fin[1] >= fin[0]) {
			swap(last, secondLast);
		}

		range(i, 2, n) {
			if (fin[i] >= fin[last]) {
				secondLast = last;
				last = i;
			}
			else if (fin[i] >= fin[secondLast]) {
				secondLast = i;
			}
		}

		if (k == 1) {
			print(last + 1 << " " << fin[last]);
		}
		else {
			print(secondLast + 1 << " " << fin[secondLast]);
		}

		graph.clear();
	}
}