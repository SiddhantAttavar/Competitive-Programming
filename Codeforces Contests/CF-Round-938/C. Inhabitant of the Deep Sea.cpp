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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		int l = 0, r = n - 1;
		bool flag = true;
		while (k > 0 and l < r) {
			// print(l, r, flag, k, a[l], a[r]);
			if (flag) {
				if (a[l] <= a[r] and 2 * a[l] - 1 <= k) {
					k -= 2 * a[l] - 1;
					a[r] -= a[l] - 1;
					l++;
					flag = false;
				}
				else if (2 * a[r] <= k) {
					k -= 2 * a[r];
					a[l] -= a[r];
					r--;
				}
				else {
					break;
				}
			}
			else {
				if (a[r] <= a[l] and 2 * a[r] - 1 <= k) {
					k -= 2 * a[r] - 1;
					a[l] -= a[r] - 1;
					r--;
					flag = true;
				}
				else if (2 * a[l] <= k) {
					k -= 2 * a[l];
					a[r] -= a[l];
					l++;
				}
				else {
					break;
				}
			}
		}

		if (l == r and k > 0) {
			if (a[l] <= k) {
				l++;
			}
		}

		print(l + n - r - 1);
	}
}
