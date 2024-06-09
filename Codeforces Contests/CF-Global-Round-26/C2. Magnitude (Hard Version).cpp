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
const int MOD = 998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> f(n + 1, 0), g(n + 1, 0);
		vector<int> d(n + 1, 1), e(n + 1, 1);
		range(i, 0, n) {
			g[i + 1] = g[i] + a[i];
			e[i + 1] = e[i];
			if (g[i + 1] >= 0) {
				e[i + 1] = (2 * e[i]) % MOD;
			}
			if (a[i] >= 0) {
				f[i + 1] = f[i] + a[i];
				d[i + 1] = (2 * d[i]) % MOD;
				if (f[i] != g[i] and f[i + 1] == abs(g[i + 1])) {
					d[i + 1] = (d[i + 1] + e[i]) % MOD;
				}
			}
			else if (f[i] == g[i]) {
				f[i + 1] = abs(f[i] + a[i]);
				d[i + 1] = d[i];
				if ((f[i] + a[i]) >= 0) {
					d[i + 1] = (2 * d[i]) % MOD;
				} 
			}
			else {
				f[i + 1] = max(f[i] + a[i], abs(g[i + 1]));
				d[i + 1] = 0;
				if (f[i + 1] == (f[i] + a[i])) {
					d[i + 1] = (2 * d[i]) % MOD;
				}
				if (f[i + 1] == abs(g[i + 1])) {
					d[i + 1] = (d[i + 1] + e[i]) % MOD;
				}
			}
		}

		print(d[n]);
	}
}
