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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<int>> graph(n);
		range(i, 0, n - 1) {
			int u, v;
			input(u, v);

			graph[u - 1].push_back(v - 1);
			graph[v - 1].push_back(u - 1);
		}

		string s;
		input(s);

		if (s[0] != '?') {
			int x = 0, y = 0;
			range(i, 1, n) {
				if (graph[i].size() == 1) {
					x += s[i] == '1' + '0' - s[0];
					y += s[i] == '?';
				}
			}

			print(x + (y + 1) / 2);
			continue;
		}

		int x = 0, y = 0, z = 0, w = 0;
		range(i, 1, n) {
			if (graph[i].size() == 1) {
				x += s[i] == '0';
				y += s[i] == '1';
				z += s[i] == '?';
			}
			else {
				w += s[i] == '?';
			}
		}

		print(max(x, y) + (z + ((x == y) * w % 2)) / 2);
	}
}
