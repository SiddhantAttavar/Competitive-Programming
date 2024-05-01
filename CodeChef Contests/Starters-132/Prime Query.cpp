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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> b(n + 1, 0), c(n + 1, 0);
		range(i, 0, n) {
			b[i + 1] = b[i] + (a[i] == 1);
			c[i + 1] = c[i] + (a[i] == 2);
		}

		int q;
		input(q);
		while (q--) {
			int l, r, k;
			input(l, r, k);

			l--;
			r--;

			int x = b[r + 1] - b[l];
			int y = c[r + 1] - c[l];
			int z = (r - l + 1) - x - y;

			if (x > y) {
				swap(x, y);
			}

			int s = min({y - x, k, z});
			x += s;
			k -= s;
			z -= s;

			if (k == 0) {
				print(x * y);
			}
			else if (x == y) {
				k = min(k, z);
				x += k / 2;
				y += k / 2 + k % 2;
				print(x * y);
			}
			else {
				int t = min(k, (y - x) / 2);
				x += t;
				y -= t;
				print(x * y);
			}
		}
	}
}
