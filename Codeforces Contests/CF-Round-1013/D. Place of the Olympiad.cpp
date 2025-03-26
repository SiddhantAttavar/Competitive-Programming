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

bool check(int n, int m, int k, int x) {
	int t = (m + 1) / (x + 1);
	return t * n * x + max(0ll, m - t * (x + 1)) * n >= k;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		int l = 1, r = 1e9, res = 1e9;
		while (l <= r) {
			int x = (l + r) / 2;
			if (check(n, m, k, x)) {
				res = x;
				r = x - 1;
			}
			else {
				l = x + 1;
			}
		}
		print(res);
	}
}
