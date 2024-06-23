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
		int n, m;
		input(n, m);

		vector<vector<int>> a(n, vector<int>(m));
		range(i, 0, n) {
			arrPut(a[i]);
		}

		range(i, 0, n) {
			range(j, 0, m) {
				int c = 0;
				
				if (i > 0 and a[i - 1][j] >= a[i][j]) {
					continue;
				}
				else if (i > 0) {
					c = a[i - 1][j];
				}

				if (i < n - 1 and a[i + 1][j] >= a[i][j]) {
					continue;
				}
				else if (i < n - 1) {
					c = max(c, a[i + 1][j]);
				}

				if (j > 0 and a[i][j - 1] >= a[i][j]) {
					continue;
				}
				else if (j > 0) {
					c = max(c, a[i][j - 1]);
				}

				if (j < m - 1 and a[i][j + 1] >= a[i][j]) {
					continue;
				}
				else if (j < m - 1) {
					c = max(c, a[i][j + 1]);
				}

				a[i][j] = c;
			}
		}

		range(i, 0, n) {
			arrPrint(a[i]);
		}
	}
}
