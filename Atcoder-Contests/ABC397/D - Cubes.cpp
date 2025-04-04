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

	for (int k = 1; k * k * k <= n; k++) {
		int l = 1, r = 1e9, res = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			__int128_t x = m;
			if ((x + k) * (x + k) * (x + k) - x * x * x >= n) {
				r = m - 1;
				res = m;
			} 
			else {
				l = m + 1;
			}
		}

		__int128_t x = res;
		if ((x + k) * (x + k) * (x + k) - x * x * x == n) {
			print(res + k, res);
			return 0;
		}
	}
	print(-1);
}
