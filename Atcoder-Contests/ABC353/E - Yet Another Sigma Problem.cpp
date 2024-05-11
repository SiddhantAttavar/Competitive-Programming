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

int dfs(int u, int p, int d, vector<vector<int>> &tree, vector<int> &s) {
	int res = 0;
	int x = 0;
	for (int v : tree[u]) {
		if (v != -1) {
			x += s[v];
		}
	}
	int y = 0;
	for (int v : tree[u]) {
		if (v == -1) {
			continue;
		}
		res += dfs(v, u, d + 1, tree, s);
		y += d * s[v] * (x - s[v]);
	}
	// print(u, p, y);
	return res + y / 2 + d * ((s[u] - x) * x + (s[u] - x) * (s[u] - x - 1) / 2);
}

int32_t main() {
	setup();

	int n;
	input(n);
	
	vector<string> a(n);
	arrPut(a);

	vector<vector<int>> tree = {vector<int>(26, -1)};
	vector<int> v = {0};
	for (string s : a) {
		int u = 0;
		v[0]++;
		for (char c : s) {
			if (tree[u][c - 'a'] == -1) {
				tree[u][c - 'a'] = tree.size();
				tree.push_back(vector<int>(26, -1));
				v.push_back(0);
			}
			u = tree[u][c - 'a'];
			v[u]++;
		}
	}

	print(dfs(0, -1, 0, tree, v));
}
