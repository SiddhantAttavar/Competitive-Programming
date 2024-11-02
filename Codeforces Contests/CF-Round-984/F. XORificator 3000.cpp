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
const int MOD = (int) 1e9 + 7; //998244353

int pref_xor(int a) {
	if (a % 4 == 0) {
		return a;
	}
	if (a % 4 == 1) {
		return a ^ (a - 1);
	}
	if (a % 4 == 2) {
		return a ^ (a - 1) ^ (a - 2);
	}
	return 0;
}

int range_xor(int a, int b) {
	int res = 0;
	range(i, a, b + 1) {
		res ^= i;
	}
	return pref_xor(b) ^ pref_xor(max(0ll, a - 1));
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int l, r, i, k;
		input(l, r, i, k);

		i = 1 << i;
		k %= i;

		int res = range_xor(l, r);
		if (k > r) {
			print(res);
			continue;
		}

		int a = 0, b = 2e18 / i, c = 0;
		while (a <= b) {
			int m = (a + b) / 2;
			if (m * i + k >= l) {
				c = m;
				b = m - 1;
			}
			else {
				a = m + 1;
			}
		}

		if (c * i + k > r) {
			print(res);
			continue;
		}

		a = c, b = 2e18 / i;
		int d = c;
		while (a <= b) {
			int m = (a + b) / 2;
			if (m * i + k <= r) {
				d = m;
				a = m + 1;
			}
			else {
				b = m - 1;
			}
		}

		res ^= range_xor(c, d) * i;
		if ((d - c + 1) % 2) {
			res ^= k;
		}
		print(res);
	}
}
