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
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> pref(n, 0), suff(n, 0);
		int l = 0, r = n - 1;
		range(i, 1, n) {
			if (a[i] >= a[i - 1]) {
				l = i;
			}
			if (l) {
				pref[i] = pref[l - 1] + 1;
			}
		}

		for (int i = n - 2; i >= 0; i--) {
			if (a[i] >= a[i + 1]) {
				r = i;
			}
			if (r < n - 1) {
				suff[i] = suff[r + 1] + 1;
			}
		}

		int res = min(suff[0], pref[n - 1] + 1);
		range(i, 0, n - 1) {
			res = min(res, pref[i] + suff[i + 1] + 1);
		}
		print(res);
	}
}
