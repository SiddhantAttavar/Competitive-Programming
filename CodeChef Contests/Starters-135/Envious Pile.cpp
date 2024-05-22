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

bool flag = true;
void dfs(int u, vector<bool> &vis, vector<vector<int>> &graph, vector<int> &s, int x) {
	vis[u] = true;
	if (u < x) {
		flag = false;
		return;
	}
	for (int v : graph[u]) {
		if (vis[v]) {
			continue;
		}

		if (flag) {
			s.push_back(u + v);
		}
		dfs(v, vis, graph, s, x);
		if (!flag) {
			return;
		}
		s.pop_back();
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, w;
		input(n, w);

		vector<int> a(n);
		arrPut(a);
		
		map<int, int> m;
		range(i, 0, n) {
			m[a[i]] = i;
		}

		vector<vector<int>> graph(5001);
		for (int i : a) {
			range(j, 1, i) {
				graph[j].push_back(i - j);
			}
		}

		vector<bool> vis(5001, false);
		vector<int> s;
		flag = true;
		dfs(w, vis, graph, s, a[0]);

		if (flag) {
			print(-1);
			continue;
		}

		range(i, 0, s.size()) {
			s[i] = m[s[i]] + 1;
		}

		range(i, 0, n) {
			s.push_back(i + 1);
			s.push_back(i + 1);
		}
		print(s.size());
		arrPrint(s);
	}
}
