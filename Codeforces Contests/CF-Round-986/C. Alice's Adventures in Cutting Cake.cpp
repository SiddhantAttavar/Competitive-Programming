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
const int MOD = (int) 1e9 + 7; //998244353

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, v;
		input(n, m, v);

		vector<int> a(n);
		arrPut(a);

		vector<int> pref(n + 1, 0);
		range(i, 0, n) {
			pref[i + 1] = pref[i] + a[i];
		}

		vector<int> f(n, 0), g(n, 0);
		range(i, 0, n) {
			int j = (upper_bound(pref.begin(), pref.end(), pref[i + 1] - v) - pref.begin()) - 1;
			if (j > 0) {
				f[i] = f[j - 1] + 1;
			}
			else if (j == 0) {
				f[i] = 1;
			}
		}

		if (f[n - 1] < m) {
			print(-1);
			continue;
		}

		g.push_back(0);
		for (int i = n - 1; i >= 0; i--) {
			int j = lower_bound(pref.begin(), pref.end(), pref[i] + v) - pref.begin();
			if (j <= n) {
				g[i] = g[j] + 1;
			}
		}

		int l = -1, res = 0;
		range(i, 0, n) {
			while ((l == -1 and g[i + 1] < m) or (l >= 0 and f[l] + g[i + 1] < m)) {
				l++;
			}
			res = max(res, pref[i + 1] - pref[l + 1]);
		}
		print(res);
	}
}
