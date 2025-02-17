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

		vector<int> a(n);
		arrPut(a);

		vector<vector<int>> b(n, vector<int>(20, -1));
		vector<int> c(n, -1);
		range(i, 0, n) {
			if (c[a[i] - 1] != -1) {
				b[i][0] = c[a[i] - 1];
			}
			range(j, 1, 20) {
				if (i < (1 << (j - 1))) {
					break;
				}

				b[i][j] = min(b[i][j - 1], b[i - (1 << (j - 1))][j - 1]);
			}
			c[a[i] - 1] = i;
		}

		// range(i, 0, n) {
		// 	arrPrint(b[i]);
		// }

		int l = 0;
		int res = 0;
		range(i, 0, n) {
			int j = b[i][0];
			if (j < l) {
				continue;
			}

			int u = i;
			int x = i;
			// print('x', i, j);
			for (int k = 19; k >= 0; k--) {
				if (u - (1 << k) >= j) {
					x = min(x, b[u][k]);
					u -= 1 << k;
				}
			}

			if (x < l or i % 2 == x % 2) {
				continue;
			}

			int y = x;
			x += (i - x + 1) / 2;
			int v = i;
			// print('y', i, x);
			for (int k = 19; k >= 0; k--) {
				if (v - (1 << k) >= x) {
					y = min(y, b[v][k]);
					v -= 1 << k;
				}
			}
			// print(y);

			if (y >= l) {
				// print('d', i, x);
				res++;
				l = i + 1;
			}
		}

		// print("res");
		print(res);
	}
}
