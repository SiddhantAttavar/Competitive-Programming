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
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<int> a(n), b(n);
		arrPut(a);
		arrPut(b);

		vector<int> c, d;
		range(i, 0, n) {
			if (b[i] == 1) {
				c.push_back(a[i]);
			}
			else {
				d.push_back(a[i]);
			}
		}

		sort(c.rbegin(), c.rend());
		sort(d.rbegin(), d.rend());

		vector<int> pref(c.size() + 1, 0);
		range(i, 0, c.size()) {
			pref[i + 1] = pref[i] + c[i];
		}

		int res = 1e9;
		if (pref.back() >= m) {
			res = lower_bound(pref.begin(), pref.end(), m) - pref.begin();
		}

		int x = 0;
		range(i, 0, d.size()) {
			x += d[i];
			if (x + pref.back() >= m) {
				res = min(res, 2 * (i + 1) + (int) (lower_bound(pref.begin(), pref.end(), m - x) - pref.begin()));
			}
		}

		if (res == 1e9) {
			print(-1);
		}
		else {
			print(res);
		}
	}
}
