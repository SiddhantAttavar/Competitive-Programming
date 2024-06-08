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

void dfs(int u, vector<int> &a, vector<int> &st, vector<bool> &in_stack, vector<int> &cycle_size, vector<int> &x, vector<bool> &vis) {
	in_stack[u] = true;
	st.push_back(u);
	vis[u] = true;
	if (!vis[a[u]]) {
		dfs(a[u], a, st, in_stack, cycle_size, x, vis);
	}
	else if (in_stack[a[u]]) {
		x.push_back(0);
		while (st[st.size() - x.back() - 1] != a[u]) {
			x.back()++;
		}
		x.back()++;
		range(i, 0, x.back()) {
			cycle_size[st[st.size() - i - 1]] = x.back();
		}
		cycle_size[a[u]] = x.back();
	}
	st.pop_back();
	in_stack[u] = false;
}

int dfs2(int u, int x, vector<vector<int>> &c) {
	int res = x;
	for (int v : c[u]) {
		res += dfs2(v, x + 1, c);
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	range(i, 0, n) {
		a[i]--;
	}
	
	vector<bool> s(n, true), b(n, false);
	for (int i : a) {
		s[i] = false;
	}

	vector<bool> in_stack(n, false), vis(n, false);
	vector<int> x, cycle_size(n, 0), st;
	range(i, 0, n) {
		if (!vis[i]) {
			dfs(i, a, st, in_stack, cycle_size, x, vis);
		}
	}

	vector<vector<int>> c(n);
	range(i, 0, n) {
		c[a[i]].push_back(i);
	}

	int res = 0;
	for (int i : x) {
		res += i * i;
	}

	range(i, 0, n) {
		if (!cycle_size[i]) {
			continue;
		}

		for (int j : c[i]) {
			if (!cycle_size[j]) {
				res += dfs2(j, cycle_size[i] + 1l, c);
			}
		}
	}
	print(res);
}
