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

void dfs(int u, vector<int> &p, vector<bool> &v, vector<bool> &b) {
	v[u] = true;
	if (!v[p[u]]) {
		dfs(p[u], p, v, b);
		return;
	}

	int x = p[u];
	b[u] = true;
	while (x != u) {
		b[x] = true;
		x = p[x];
	}
}

void dfs2(int u, vector<int> &p, vector<int> &res, string &s) {
	if (res[p[u]] == -1) {
		dfs2(p[u], p, res, s);
	}
	res[u] = res[p[u]] + s[u] == '0';
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> p(n);
		arrPut(p);

		range(i, 0, n) {
			p[i]--;
		}

		string s;
		input(s);

		vector<bool> v(n, false), b(n, false);
		range(i, 0, n) {
			if (!v[i]) {
				dfs(i, p, v, b);
			}
		}

		vector<int> res(n, -1);
		range(i, 0, n) {
			if (!b[i] or res[i] != -1) {
				continue;
			}

			int u = p[i];
			res[i] = s[i] == '0';
			while (u != i) {
				res[i] += s[u] == '0';
				u = p[u];
			}

			u = p[i];
			while (u != i) {
				res[u] = res[i];
				u = p[u];
			}
		}

		range(i, 0, n) {
			if (res[i] == -1) {
				dfs2(i, p, res, s);
			}
		}

		arrPrint(res);
	}
}
