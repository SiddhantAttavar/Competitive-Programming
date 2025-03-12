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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		
		vector<int> a(n);
		arrput(a);
		
		vector<int> f(n), g(n), h(n);
		f[0] = 1;
		h[0] = 1;
		g[0] = 0;
		rep(i, 1, n) {
			f[i] = f[i - 1];
			if (a[i] > f[i]) {
				f[i]++;
			}
			else if (a[i] < f[i]) {
				f[i]--;
			}
			h[i] = max(h[i - 1], f[i]);

			g[i] = max(i == 1 ? 0 : h[i - 2], g[i - 1]);
			if (a[i] > g[i]) {
				g[i]++;
			}
			else if (a[i] < g[i]) {
				g[i]--;
			}
		}

		print(max(g[n - 1], n >= 2 ? h[n - 2] : 0));
	}
}
