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
		int n, x;
		input(n, x);

		int res = 0;
		range(s, 2, x) {
			print(res, s);
			int k = x - s;

			int l = 1, r = s / 2, u = 1;
			if (k <= n - r * (n - r)) {
				res += (s - 1) * k;
				continue;
			}
			while (l <= r) {
				int m = (l + r) / 2;
				if (n - m * (s - m) > k) {
					u = m;
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}

			l = (s + 1) / 2, r = s - 1;
			int v = s - 1;
			while (l <= r) {
				int m = (l + r) / 2;
				if (n - m * (s - m) > k) {
					v = m;
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}

			int c = k * (v - u - 2);
			v = s - v;
			c += n * (u + v);
			c -= s * (u * (u + 1) + v * (v + 1)) / 2;
			c += (u * (u + 1) * (2 * u + 1) + v * (v + 1) * (2 * v + 1)) / 6;
			res += (s - 1) * c;
		}
		print(res);
	}
}
