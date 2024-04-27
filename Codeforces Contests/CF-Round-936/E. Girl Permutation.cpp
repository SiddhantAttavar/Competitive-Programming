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
const int MOD = (int) 1e9 + 7;

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

int dfs(int u, int p, vector<vector<int>> &graph, vector<int> &s, vector<int> &fact) {
	int res = 1;
	for (int v : graph[u]) {
		if (v == p) {
			continue;
		}

		res = (res * dfs(v, u, graph, s, fact)) % MOD;
		res = mod_div(res, fact[s[v]]);
		s[u] += s[v];
	}
	return (res * fact[s[u] - 1]) % MOD;
}

int32_t main() {
	int N = 2e5;
	vector<int> fact(N + 1, 1);
	range(i, 2, N + 1) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}

	setup(); int tc; input(tc); while (tc--) {
		int n, x, y;
		input(n, x, y);

		vector<int> a(x), b(y);
		arrPut(a);
		arrPut(b);

		if (a.back() != b[0] or a[0] != 1 or b.back() != n) {
			print(0);
			continue;
		}

		vector<vector<int>> graph(n);
		int j = 0;
		range(i, 0, a.back() - 1) {
			if (a[j] - 1 == i) {
				j++;
				graph[a[j] - 1].push_back(i);
			}
			else {
				graph[a[j - 1] - 1].push_back(i);
			}
		}

		reverse(b.begin(), b.end());
		j = 0;
		for (int i = n - 1; i > b.back() - 1; i--) {
			if (b[j] - 1 == i) {
				j++;
				graph[b[j] - 1].push_back(i);
			}
			else {
				graph[b[j - 1] - 1].push_back(i);
			}
		}

		vector<int> s(n, 1);
		print(dfs(a.back() - 1, -1, graph, s, fact));
	}
}
