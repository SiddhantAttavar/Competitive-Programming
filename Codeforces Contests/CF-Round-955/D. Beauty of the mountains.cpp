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
		int n, m, k;
		input(n, m, k);

		vector<vector<int>> a(n, vector<int>(m));
		range(i, 0, n) {
			arrPut(a[i]);
		}

		vector<string> b(n);
		arrPut(b);

		vector<vector<int>> c(n + 1, vector<int>(m + 1, 0)), d(n + 1, vector<int>(m + 1, 0));
		int x = 0;
		range(i, 0, n) {
			range(j, 0, m) {
				c[i + 1][j + 1] = c[i][j + 1] + c[i + 1][j] - c[i][j];
				d[i + 1][j + 1] = d[i][j + 1] + d[i + 1][j] - d[i][j];
				if (b[i][j] == '0') {
					c[i + 1][j + 1]++;
					x += a[i][j];
				}
				else {
					d[i + 1][j + 1]++;
					x -= a[i][j];
				}
			}
		}

		x = abs(x);
		if (x == 0) {
			print("YES");
			continue;
		}

		int res = 0;
		range(i, k, n + 1) {
			range(j, k, m + 1) {
				int y = abs((c[i][j] - c[i - k][j] - c[i][j - k] + c[i - k][j - k]) - (d[i][j] - d[i - k][j] - d[i][j - k] + d[i - k][j - k]));
				res = __gcd(res, y);
				// print(res, y, i, j);
			}
		}
		// arrPrint(b); 

		if (res != 0 and x % res == 0) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
