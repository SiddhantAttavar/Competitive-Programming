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
		int n;
		input(n);

		string s;
		input(s);

		int x = 0;
		for (char c : s) {
			x += c == '1';
		}

		int y = 0;
		int res = -1;
		if (2 * x >= n) {
			res = 0;
		}
		range(i, 0, n) {
			y += s[i] == '1';
			x -= s[i] == '1';
			if (2 * (i + 1 - y) >= (i + 1) and 2 * x >= (n - i - 1)) {
				// print('d', i);
				if (abs(n - 2 * res) > abs(n - 2 * (i + 1))) {
					res = i + 1;
				}
			}
		}
		print(res);
	}
}
