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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

bool check(vector<int> &a, int n, int x, int m) {
	int s = x;
	ordered_set o;
	range(i, 0, m) {
		s -= a[i];
		o.insert(-a[i]);
	}

	if (s >= 0) {
		return true;
	}

	int y = 0;
	range(i, m, n) {
		s -= a[i];
		int k = o.order_of_key(-a[i]);
		o.insert(-a[i]);
		int z = *o.find_by_order(i - m);
		if (k <= (i - m)) {
			z = -a[i];
		}
		if (z < 0) {
			y -= (z - 1) / 2;
		}
		else {
			y += z;
		}
		if ((s + y) >= 0) {
			return true;
		}
	}
	return false;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, x;
		input(n, x);
		
		vector<int> a(n);
		arrPut(a);

		int l = 0, r = n, res = (x >= 0) - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(a, n, x, m)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}
