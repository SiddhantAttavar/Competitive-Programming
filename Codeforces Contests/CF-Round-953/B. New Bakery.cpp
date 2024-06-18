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
		int n, a, b;
		input(n, a, b);

		int l = 0, r = min(n, b), res = 0;
		while (l <= r) {
			int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			int x = (n - m1) * a + (m1 * (2 * b - m1 + 1)) / 2;
			int y = (n - m2) * a + (m2 * (2 * b - m2 + 1)) / 2;
			if (x == y) {
				res = m1;
				l = m1 + 1;
				r = m2 - 1;
			}
			else if (x < y) {
				res = m2;
				l = m1 + 1;
			}
			else {
				res = m1;
				r = m2 - 1;
			}
		}
		print((n - res) * a + (res * (2 * b - res + 1)) / 2);
	}
}
