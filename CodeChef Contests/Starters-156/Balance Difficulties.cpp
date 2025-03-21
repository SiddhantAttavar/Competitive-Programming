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

bool solve(vector<int> &a, int k, int x) {
	a[0] += k;
	range(i, 1, a.size()) {
		if (a[i] - a[i - 1] > x + k) {
			return false;
		}
		a[i] = min(a[i] + k, a[i - 1] + x);
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);

		vector<int> b(n);
		arrPut(b);

		int l = 0, r = 5e9, res = -1;
		while (l <= r) {
			int m = (l + r) / 2;
			vector<int> a(b.begin(), b.end());
			if (solve(a, m, x)) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}

		print(res);
		solve(b, res, x);
		arrPrint(b);
	}
}
