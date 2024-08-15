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

int32_t main() {
	map<string, int> m = {
		{"BG", 0},
		{"BR", 1},
		{"BY", 2},
		{"GR", 3},
		{"GY", 4},
		{"RY", 5}
	};
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> a(n);
		range(i, 0, n) {
			string s;
			input(s);
			a[i] = m[s];
		}

		vector<vector<int>> p(n, vector<int>(6, -1)), s(n, vector<int>(6, -1));
		p[0][a[0]] = 0;
		range(i, 1, n) {
			range(j, 0, 6) {
				p[i][j] = p[i - 1][j];
			}
			p[i][a[i]] = i;
		}

		s[n - 1][a[n - 1]] = n - 1;
		for (int i = n - 2; i >= 0; i--) {
			range(j, 0, 6) {
				s[i][j] = s[i + 1][j];
			}
			s[i][a[i]] = i;
		}

		while (q--) {
			int u, v;
			input(u, v);

			u--;
			v--;

			if (u > v) {
				swap(u, v);
			}

			if (a[u] != 5 - a[v]) {
				print(v - u);
				continue;
			}

			int res = 2 * n;
			range(j, 0, 6) {
				if (j == a[u] or j == a[v]) {
					continue;
				}

				if (p[v][j] != -1) {
					res = min(res, abs(u - p[v][j]) + abs(v - p[v][j]));
				}
				if (s[u][j] != -1) {
					res = min(res, abs(u - s[u][j]) + abs(v - s[u][j]));
				}
			}

			if (res == 2 * n) {
				print(-1);
			}
			else {
				print(res);
			}
		}
	}
}
