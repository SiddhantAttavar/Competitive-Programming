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

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		vector<int> pref(n, 0), suff(n, 0);
		range(i, 1, n) {
			pref[i] = pref[i - 1];
			if (i == 1 or (a[i] - a[i - 1] < a[i - 1] - a[i - 2])) {
				pref[i]++;
			}
			else {
				pref[i] += a[i] - a[i - 1];
			}
		}

		for (int i = n - 2; i >= 0; i--) {
			suff[i] = suff[i + 1];
			if (i == n - 2 or (a[i + 1] - a[i] < a[i + 2] - a[i + 1])) {
				suff[i]++;
			}
			else {
				suff[i] += a[i + 1] - a[i];
			}
		}

		// arrPrint(pref);
		// arrPrint(suff);

		int m; input(m); while (m--) {
			int x, y;
			input(x, y);

			x--;
			y--;

			// print(x, y);
			// cout.flush();

			if (x > y) {
				print(suff[y] - suff[x]);
			}
			else {
				print(pref[y] - pref[x]);
			}
		}
	}
}
