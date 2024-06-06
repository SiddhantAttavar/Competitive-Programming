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

		vector<int> x(n), p(n);
		arrPut(x);
		arrPut(p);

		vector<int> a(n, false), b(n, false), c(n, false), d(n, false);
		a[0] = true;
		b[0] = true;
		c[n - 1] = true;
		d[n - 1] = true;
		range(i, 1, n) {
			a[i] = a[i - 1] and x[i - 1] + p[i - 1] >= x[i];
			b[i] = b[i - 1] and x[i] - p[i] <= x[i - 1];
		}
		for (int i = n - 2; i >= 0; i--) {
			c[i] = c[i + 1] and x[i + 1] - p[i + 1] <= x[i];
			d[i] = d[i + 1] and x[i] + p[i] >= x[i + 1];
		}

		bool flag = false;
		range(i, 1, n) {
			if ((a[i - 1] or b[i - 1]) and (c[i] or d[i])) {
				flag = true;
				break;
			}
		}

		if (flag) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
