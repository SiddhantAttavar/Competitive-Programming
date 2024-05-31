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
		int n, m;
		input(n, m);

		vector<int> a(n + m + 1), b(n + m + 1);
		arrPut(a);
		arrPut(b);

		vector<int> res(n + m + 1, 0);
		vector<bool> c(n + m, false);
		int x = 0, y = 0;
		int u = -1;
		range(i, 0, n + m) {
			if ((a[i] > b[i] and x < n) or y == m) {
				res[n + m] += a[i];
				x++;
			}
			else {
				c[i] = true;
				res[n + m] += b[i];
				y++;
			}

			if (u == -1 and (x == n or y == m)) {
				u = i;
			}
		}

		if (!c[n + m - 1]) {
			swap(a, b);
		}

		int k = 0;
		range(i, u + 1, n + m) {
			if (a[i] > b[i]) {
				k = a[i] - b[i];
				break;
			}
		}

		range(i, 0, n + m) {
			res[i] = res[n + m];
			if (c[i] == c[n + m - 1]) {
				res[i] += b[n + m] - b[i];
			}
			else {
				if (k == 0) {
					res[i] += a[n + m] - a[i];
				}
				else {
					res[i] += k + b[n + m] - a[i];
				}
			}
		}

		arrPrint(res);
	}
}
