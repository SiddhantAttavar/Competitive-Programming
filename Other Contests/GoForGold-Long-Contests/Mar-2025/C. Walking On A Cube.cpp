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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n;
	input(n);

	int a, b, c, x, y, z;
	input(a, b, c);
	input(x, y, z);

	int res = abs(a - x) + abs(b - y) + abs(c - z);
	if (min(a, x) == 0 and max(a, x) == n) {
		print(res + min({
			b + y - abs(b - y),
			2 * n - b - y - abs(b - y),
			c + z - abs(c - z),
			2 * n - c - z - abs(c - z)
		}));
	}
	else if (min(b, y) == 0 and max(b, y) == n) {
		print(res + min({
			a + x - abs(a - x),
			2 * n - a - x - abs(a - x),
			c + z - abs(c - z),
			2 * n - c - z - abs(c - z)
		}));
	}
	else if (min(c, z) == 0 and max(c, z) == n) {
		print(res + min({
			a + x - abs(a - x),
			2 * n - a - x - abs(a - x),
			b + y - abs(b - y),
			2 * n - b - y - abs(b - y)
		}));
	}
	else {
		print(res);
	}
}
