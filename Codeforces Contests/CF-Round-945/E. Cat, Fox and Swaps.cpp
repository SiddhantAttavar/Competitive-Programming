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

		vector<int> p(n);
		arrPut(p);

		int res = 1;
		int x = -1;
		range(i, 1, n) {
			if (i != p[i] - 1) {
				if (x == -1) {
					x = i + p[i];
				}
				else if (x != i + p[i]) {
					res--;
					break;
				}
			}
		}

		if (x == -1) {
			print(n * (2 * n + 1));
			continue;
		}

		int l = 0, r = 2 * n;
		range(i, 0, n) {
			if (i != p[i] - 1) {
				l = max(l, p[i] + 1);
				r = min(r, p[i] + n);
			}
		}

		print(res + n * (2 * n - 1) - (l - 2) * (l - 1) / 2 - (2 * n - r) * (2 * n - r - 1) / 2);
	}
}
