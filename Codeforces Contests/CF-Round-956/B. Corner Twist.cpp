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

		vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
		range(i, 0, n) {
			string s;
			input(s);
			range(j, 0, m) {
				a[i][j] = s[j] - '0';
			}
		}
		range(i, 0, n) {
			string s;
			input(s);
			range(j, 0, m) {
				b[i][j] = s[j] - '0';
			}
		}

		int x = 0, y = 0;
		range(i, 0, n) {
			range(j, 0, m) {
				x += a[i][j];
				y += b[i][j];
			}
		}

		if (x % 3 != y % 3) {
			print("NO");
			continue;
		}

		range(i, 0, n - 1) {
			range(j, 0, m - 1) {
				while (a[i][j] != b[i][j]) {
					a[i][j] = (a[i][j] + 1) % 3;
					a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;
					a[i][j + 1] = (a[i][j + 1] + 2) % 3;
					a[i + 1][j] = (a[i + 1][j] + 2) % 3;
				}
			}
		}

		bool flag = true;
		range(i, 0, n) {
			if (a[i][m - 1] != b[i][m - 1]) {
				flag = false;
				break;
			}
		}
		range(j, 0, m - 1) {
			if (a[n - 1][j] != b[n - 1][j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
