#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int xor_sum(int a) {
	if (a % 4 == 0) {
		return a;
	}
	else if (a % 4 == 1) {
		return 1;
	}
	else if (a % 4 == 2) {
		return a + 1;
	}
	return 0;
}

int solve(int x, int y) {
	if (x > y) {
		swap(x, y);
	}

	int p = (x + 1) / 2;
	int res = xor_sum(p - 1) * 2;

	if (x % 2 == 0) {
		res ^= xor_sum(y) ^ xor_sum(x - 1);
	}

	res ^= 2 * (xor_sum((x + y) / 2) ^ xor_sum((x + y) / 2 - p)) + (((x + y) % 2) & (p % 2));

	return res;
}

int32_t main() {

	// range(i, 0, 100) {
	// 	int x = 0;
	// 	range(j, 0, 100) {
	// 		range(k, 0, i + 1) {
	// 			x ^= k + j;
	// 		}
	// 		print(i, j, x);
	// 		cout.flush();
	// 		assert(x == solve(i, j));
	// 	}
	// }

	setup(); int tc; input(tc); while (tc--) {
		int n, m, x, y;
		input(n, m, x, y);

		// print("");
		// print(solve(n - x, y - 1) ^ solve(0, n - x));

		print(
			solve(x - 1, y - 1) ^ solve(x - 1, 0) ^ solve(0, y - 1) ^
			solve(x - 1, m - y) ^ solve(0, m - y) ^
			solve(n - x, y - 1) ^ solve(n - x, 0) ^
			solve(n - x, m - y)
		);
	}
}
