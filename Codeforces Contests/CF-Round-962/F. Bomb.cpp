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

int check(int x, vector<int> &a, vector<int> &b) {
	int n = a.size(), c = 0;
	range(i, 0, n) {
		int y = max(0ll, (a[i] - x + b[i] - 1) / b[i]);
		c += y;
	}
	return c;
}

int solve(int x, int k, vector<int> &a, vector<int> &b) {
	int n = a.size(), c = 0, res = 0;
	range(i, 0, n) {
		int y = max(0ll, (a[i] - x + b[i] - 1) / b[i]);
		c += y;
		res += y * (2 * a[i] - (y - 1) * b[i]) / 2;
		a[i] -= y * b[i];
	}
	range(i, 0, n) {
		if (a[i] == x and c < k) {
			c++;
			res += x;
		}
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		int l = 1, r = 1e9, res = 1e9;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(m, a, b) <= k) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		print(solve(res, k, a, b));
	}
}
