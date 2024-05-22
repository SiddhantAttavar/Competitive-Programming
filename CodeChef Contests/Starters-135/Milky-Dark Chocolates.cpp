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

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		vector<vector<int>> f(n, vector<int>(k, 1e15)), g(n, vector<int>(k, 1e15));
		f[0][0] = a[0];
		g[0][0] = b[0];
		range(i, 1, n) {
			f[i][0] = f[i - 1][0] + a[i];
			g[i][0] = g[i - 1][0] + b[i];
			range(j, 1, k) {
				f[i][j] = min(f[i - 1][j], g[i - 1][j - 1]) + a[i];
				g[i][j] = min(g[i - 1][j], f[i - 1][j - 1]) + b[i];
			}
		}

		int res = 1e15;
		range(j, 0, k) {
			res = min({res, f[n - 1][j], g[n - 1][j]});
		}
		print(res);
	}
}
