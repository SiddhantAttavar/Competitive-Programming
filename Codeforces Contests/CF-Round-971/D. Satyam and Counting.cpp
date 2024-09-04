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

		vector<bool> a(n + 1, false), b(n + 1, false);
		range(i, 0, n) {
			int x, y;
			input(x, y);

			if (y) {
				a[x] = true;
			}
			else {
				b[x] = true;
			}
		}

		int res = 0;
		range(i, 0, n + 1) {
			if (a[i] and b[i]) {
				res += n - 2;
			}
		}

		range(i, 1, n) {
			res += a[i] and b[i - 1] and b[i + 1];
			res += b[i] and a[i - 1] and a[i + 1];
		}

		print(res);
	}
}
