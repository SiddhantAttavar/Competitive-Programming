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
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrPut(a);

		while (q--) {
			int l, r, k;
			input(l, r, k);

			l--;
			r--;

			int x = a[l], z = 0, s = abs(a[l + 1] - a[l]);
			range(i, l + 2, r + 1) {
				s += abs(a[i] - a[i - 1]);
				if (x < a[i - 1]) {
					if (a[i - 1] > a[i]) {
						z += a[i - 1] - max(a[i], x);
					}
				}
				else if (x < a[i - 1]) {
					if (a[i - 1] < a[i]) {
						z += min(a[i], x) - a[i - 1];
					}
				}
			}

			if (s <= k) {
				print(0);
				continue;
			}

			if (s - 2 * z <= k) {
				print((s - k + 1) / 2);
				continue;
			}

			print(z + s - 2 * z - k);
		}
	}
}
