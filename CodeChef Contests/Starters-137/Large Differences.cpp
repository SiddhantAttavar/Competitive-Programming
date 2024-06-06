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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		vector<int> a(n);
		arrPut(a);

		int x = 0;
		range(i, 1, n) {
			x += abs(a[i] - a[i - 1]);
		}

		int res = max({
			x,
			max(a[1] - 1, k - a[1]) + x - abs(a[0] - a[1]),
			max(a[n - 2] - 1, k - a[n - 2]) + x - abs(a[n - 1] - a[n - 2]),
		});
		range(i, 1, n - 1) {
			res = max(res, x - abs(a[i] - a[i - 1]) - abs(a[i] - a[i + 1]) + max(
				2 * k - a[i - 1] - a[i + 1],
				a[i - 1] + a[i + 1] - 2
			));
		}

		print(res);
	}
}
