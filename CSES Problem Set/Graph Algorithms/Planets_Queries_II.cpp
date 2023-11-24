#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

void dfs(int u, vector<int> &a, vector<bool> &vis, vector<bool> &in_stack, vector<vector<int>> &cycles, vector<int> &in_cycle, vector<vector<int>> &p, vector<int> &l) {
	vis[u] = true;
	in_stack[u] = true;
	if (!vis[a[u]]) {
		dfs(a[u], a, vis, in_stack, cycles, in_cycle, p, l);
	}
	else if (in_stack[a[u]]) {
		in_cycle[u] = cycles.size();
		vector<int> curr_cycle = {u};
		int o = u;
		while (a[o] != u) {
			o = a[o];
			in_cycle[o] = cycles.size();
			curr_cycle.push_back(o);
		}
		cycles.push_back(curr_cycle);
	}

	if (in_cycle[u] == -1) {
		p[u][0] = a[u];
		l[u] = l[a[u]] + 1;
		range(i, 1, 30) {
			if (p[u][i - 1] != -1) {
				p[u][i] = p[p[u][i - 1]][i - 1];
			}
		}
	}
	in_stack[u] = false;
}

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vector<int> a(n);
	arrPut(a);
	range(i, 0, n) {
		a[i]--;
	}

	vector<bool> in_stack(n, false), vis(n, false);
	vector<int> in_cycle(n, -1), cycle_ind(n, -1), in_tail(n, -1), tail_ind(n, -1), tail_end(n, -1), l(n, 0);
	vector<vector<int>> cycles, p(n, vector<int>(30, -1));
	range(i, 0, n) {
		if (!vis[i]) {
			dfs(i, a, vis, in_stack, cycles, in_cycle, p, l);
		}
	}

	for (vector<int> v : cycles) {
		range(i, 0, (int) v.size()) {
			cycle_ind[v[i]] = i;
		}
	}

	// range(i, 0, n) {
	// 	arrPrint(p[i]);
	// }
	// arrPrint(l);
	// arrPrint(in_cycle);
	// arrPrint(cycle_ind);
	// arrPrint(in_tail);
	// arrPrint(tail_ind);

	while (q--) {
		int u, v;
		input(u, v);
		u--;
		v--;

		if (in_cycle[u] != -1 and in_cycle[v] != -1 and in_cycle[u] != in_cycle[v]) {
			print(-1);
			continue;
		}

		if (in_cycle[u] != -1 and in_cycle[v] == -1) {
			print(-1);
			continue;
		}

		if (in_cycle[u] == -1 and in_cycle[v] == -1) {
			if (l[u] < l[v]) {
				print(-1);
				continue;
			}

			int res = l[u] - l[v];
			for (int i = 29; i >= 0; i--) {
				if (p[u][i] != -1 and l[p[u][i]] >= l[v]) {
					u = p[u][i];
				}
			}
			// print(u, v);

			if (u != v) {
				print(-1);
			}
			else {
				print(res);
			}
			continue;
		}

		int res = 0;
		if (in_cycle[v] != -1) {
			res = l[u];
			for (int i = 29; i >= 0; i--) {
				if (p[u][i] != -1) {
					u = p[u][i];
				}
			}
		}

		if (in_cycle[u] != in_cycle[v]) {
			print(-1);
			continue;
		}

		print(res + (cycle_ind[v] - cycle_ind[u] + cycles[in_cycle[u]].size()) % cycles[in_cycle[u]].size());
	}
}
