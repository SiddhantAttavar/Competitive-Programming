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

int sqrt(int x) {
	int l = 0, r = 1e9, res = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		if (m * m <= x) {
			res = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int k;
		input(k);

		int l = 1, r = 2e18, res = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (m - sqrt(m) >= k) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		print(res);
	}
}