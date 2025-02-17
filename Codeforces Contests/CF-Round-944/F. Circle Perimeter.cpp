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

		int res = 2;
		range(x, 1ll, n + 1) {
			int l = 0, r = n, a = -1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (x * x + m * m >= n * n) {
					r = m - 1;
					a = m;
				}
				else {
					l = m + 1;
				}
			}

			l = 0, r = n;
			int b = -1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (x * x + m * m < (n + 1) * (n + 1)) {
					l = m + 1;
					b = m;
				}
				else {
					r = m - 1;
				}
			}

			if (a != -1 and b != -1) {
				res += 4 * (b - a + 1) - 2 * (a == 0);
			}
		}
		print(res);
	}
}
