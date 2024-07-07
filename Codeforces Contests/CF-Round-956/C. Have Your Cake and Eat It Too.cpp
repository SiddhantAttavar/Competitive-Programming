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

		vector<int> a(n), b(n), c(n);
		arrPut(a);
		arrPut(b);
		arrPut(c);

		vector<int> x(n + 1, 0), y(n + 1, 0), z(n + 1, 0);
		range(i, 0, n) {
			x[i + 1] = x[i] + a[i];
			y[i + 1] = y[i] + b[i];
			z[i + 1] = z[i] + c[i];
		}
		int k = 0;
		for (int i : a) {
			k += i;
		}
		k = (k + 2) / 3;
		vector<int> res(6, -1);
		range(r, 1, n) {
			int l = lower_bound(x.begin(), x.end(), x[r + 1] - k + 1) - x.begin() - 1;
			if (l >= 0 and y[l] >= k and z[n] - z[r + 1] >= k and x[r + 1] - x[l] >= k) {
				print("debug");
				res = {l + 1, r + 1, 1, l, r + 2, n};
				break;
			}

			if (l >= 0 and z[l] >= k and y[n] - y[r + 1] >= k and x[r + 1] - x[l] >= k) {
				res = {l + 1, r + 1, r + 2, n, 1, l};
				break;
			}

			l = lower_bound(y.begin(), y.end(), y[r + 1] - k + 1) - y.begin() - 1;
			if (l >= 0 and x[l] >= k and z[n] - z[r + 1] >= k and y[r + 1] - y[l] >= k) {
				res = {1, l, l + 1, r + 1, r + 2, n};
				break;
			}

			if (l >= 0 and z[l] >= k and x[n] - x[r + 1] >= k and y[r + 1] - y[l] >= k) {
				res = {r + 2, n, l + 1, r + 1, 1, l};
				break;
			}

			l = lower_bound(z.begin(), z.end(), z[r + 1] - k + 1) - z.begin() - 1;
			if (l >= 0 and y[l] >= k and x[n] - x[r + 1] >= k and z[r + 1] - z[l] >= k) {
				res = {r + 2, n, 1, l, l + 1, r + 1};
				break;
			}

			if (l >= 0 and x[l] >= k and y[n] - y[r + 1] >= k and z[r + 1] - z[l] >= k) {
				res = {1, l, r + 2, n, l + 1, r + 1};
				break;
			}
		}

		if (res[0] == -1) {
			print(-1);
		}
		else {
			arrPrint(res);
		}
	}
}
