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

int query(int x, int y) {
	print('?', x, y);
	fflush(stdout);

	int d;
	input(d);
	return d;
}

int32_t main() {
	// setup();
	int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		int a = query(1, 1); // x + y = a + 2
		int b = query(n, m); // x + y = n + m - b
		int c = query(n, 1); // y = x + c - n + 1

		int x = (a + 1 - c + n) / 2;
		int y = x + c - n + 1;

		int d = 1;
		if (1 <= x and x <= n and 1 <= y and y <= m) {
			d = query(x, y);
		}

		if (d == 0) {
			print('!', x, y);
			fflush(stdout);
			continue;
		}

		x = (2 * n + m - b - c - 1) / 2;
		y = x + c - n + 1;
		assert(1 <= x and x <= n and 1 <= y and y <= m);
		print('!', x, y);
		fflush(stdout);
	}
}
