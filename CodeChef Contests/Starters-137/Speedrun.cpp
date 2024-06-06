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

		vector<int> a(n), h(n);
		arrPut(a);
		arrPut(h);

		vector<int> f(n, 1e15);
		if (h[0] <= a[0]) {
			f[0] = h[0];
		}
		range(i, 1, n) {
			if (f[i - 1] + h[i] <= a[i]) {
				f[i] = f[i - 1] + h[i];
			}
		}

		vector<int> g(n, 1e15);
		range(i, 0, n) {
			if (g[i - 1] + h[i] <= a[i]) {
				g[i] = g[i - 1] + h[i];
			}

			int j = lower_bound(a.begin(), a.end(), a[i] - 2 * k) - a.begin() - 1;
			if (j == -1) {
				g[i] = 0;
			}
			else {
				g[i] = min(g[i], f[j]);
			}
		}

		if (g[n - 1] <= a[n - 1]) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
