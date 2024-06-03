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
			arrPut(a[i]);
		}
		range(i, 0, n) {
			arrPut(b[i]);
		}

		vector<int> c(n * m + 1);
		range(i, 0, n) {
			for (int j : a[i]) {
				c[j] = i;
			}
		}

		sort(b.begin(), b.end(), [&](vector<int> &a, vector<int> &b) {
			return c[a[0]] < c[b[0]];
		});

		vector<int> d(n * m + 1);
		range(i, 0, n) {
			range(j, 0, m) {
				d[a[i][j]] = j;
			}
		}

		vector<vector<int>> x(m, vector<int>(n));
		range(i, 0, n) {
			range(j, 0, m) {
				x[j][i] = b[i][j];
			}
		}
		sort(x.begin(), x.end(), [&](vector<int> &a, vector<int> &b) {
			return d[a[0]] < d[b[0]];
		});

		bool res = true;
		range(i, 0, n) {
			range(j, 0, m) {
				if (a[i][j] != x[j][i]) {
					res = false;
					break;
				}
			}
		}

		if (res) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
