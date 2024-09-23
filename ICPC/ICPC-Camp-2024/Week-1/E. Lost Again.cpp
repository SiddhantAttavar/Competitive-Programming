#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}

		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int mod_div(int a, int b) {
	return (a * mod_pow(b, MOD - 2)) % MOD;
}

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &l, vector<int> &s) {
	s[u] = 1;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		dfs(v, u, graph, l, s);
		s[u] += s[v];
		l[u] += l[v] + s[v];
	}
	l[u] %= MOD;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<vector<int>> graph(n);
	range(i, 0, n - 1) {
		int u, v;
		input(u, v);

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	vector<int> l(n, 0), s(n, 0);
	dfs(0, -1, graph, l, s);
	
	int res = 0;
	range(u, 0, n) {
		for (int v : graph[u]) {
			if (s[u] > s[v]) {
				res = (res + (s[u] - s[v]) * (l[v] + s[v])) % MOD;
			}
		}
	}
	print(mod_div((res * 2) % MOD, (n * (n + 1)) % MOD));
}
